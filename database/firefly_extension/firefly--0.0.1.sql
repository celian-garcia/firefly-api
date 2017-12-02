-- complain if script is sourced in psql, rather than via CREATE EXTENSION
-- \echo Use "CREATE EXTENSION firefly" to load this file. \quit

CREATE SEQUENCE fpoint3d_id_seq
START WITH 0
INCREMENT BY 1
MINVALUE 0
NO MAXVALUE
CACHE 1;

CREATE TABLE fpoint3d (
  id         INTEGER DEFAULT nextval('fpoint3d_id_seq' :: REGCLASS) NOT NULL,
  task_id    INTEGER,
  value      POINT                                                  NOT NULL,
  operations INTEGER []                                             NOT NULL DEFAULT '{}'
);

CREATE SEQUENCE task_id_seq
START WITH 0
INCREMENT BY 1
MINVALUE 0
NO MAXVALUE
CACHE 1;

CREATE TABLE task (
  id          INTEGER DEFAULT nextval('task_id_seq' :: REGCLASS) NOT NULL,
  name        CHARACTER VARYING(20)                              NOT NULL,
  description TEXT                                               NOT NULL,
  type        INTEGER,
  module      INTEGER,
  state       INTEGER,
  "user"      CHARACTER VARYING(20),
  date        CHARACTER VARYING(20)
);

ALTER TABLE ONLY fpoint3d
  ADD CONSTRAINT "FPOINT3D_PRIMARY_KEY" PRIMARY KEY (id);

ALTER TABLE ONLY task
  ADD CONSTRAINT task_id_key UNIQUE (id);

ALTER TABLE ONLY fpoint3d
  ADD CONSTRAINT "FPOINT_3D_FOREIGN_KEY" FOREIGN KEY (task_id) REFERENCES task (id);

CREATE OR REPLACE FUNCTION hashpoint(POINT)
  RETURNS INTEGER
LANGUAGE SQL IMMUTABLE
AS 'SELECT hashfloat8($1 [0]) # hashfloat8($1 [1])';

CREATE OPERATOR CLASS point_hash_ops DEFAULT FOR TYPE POINT USING HASH AS
OPERATOR 1 ~=( POINT, POINT ),
FUNCTION 1 hashpoint( POINT );

CREATE FUNCTION make_operation_seq()
  RETURNS TRIGGER
LANGUAGE plpgsql
AS $$
BEGIN
  EXECUTE format('CREATE SEQUENCE f_operation_seq_for_task_%s', NEW.id);
  RETURN NEW;
END
$$;

CREATE TRIGGER make_operation_seq
AFTER INSERT ON task
FOR EACH ROW EXECUTE PROCEDURE make_operation_seq();

CREATE FUNCTION increase_operations(in_value POINT, in_task_id INTEGER)
  RETURNS INTEGER
LANGUAGE plpgsql
AS $$
DECLARE
  current_op    INTEGER;
  pt            FPOINT3D;
  pt_id         INTEGER;
  pt_operations INTEGER [];
BEGIN
  -- Initialize declared variables
  current_op = nextval('f_operation_seq_for_task_' || in_task_id);
  SELECT *
  INTO pt
  FROM fpoint3D
  WHERE value <-> in_value < 0.00001 AND task_id = in_task_id;
  pt_id = pt.id;
  pt_operations = pt.operations;

  -- Do the update
  UPDATE fpoint3d
  SET operations = pt_operations || current_op
  WHERE id = pt_id;

  RETURN current_op;
END
$$;

CREATE FUNCTION save_add_operation(in_value POINT, in_task_id INTEGER)
  RETURNS INTEGER
LANGUAGE plpgsql
AS $$
DECLARE
  current_op    INTEGER;
  pt_operations INTEGER [];
BEGIN

  SELECT operations
  INTO pt_operations
  FROM FPOINT3D
  WHERE value <-> in_value < 0.00001 AND task_id = in_task_id;

  EXECUTE 'SELECT last_value FROM f_operation_seq_for_task_' || in_task_id
  INTO current_op;

  IF NOT FOUND
  THEN
    INSERT INTO fpoint3d (task_id, value)
    VALUES (in_task_id, in_value);
    current_op = increase_operations(in_value, in_task_id);
  ELSE
    IF coalesce(array_length(pt_operations, 1), 0) % 2 = 0
    THEN
      current_op = increase_operations(in_value, in_task_id);
    END IF;
  END IF;

  RETURN current_op;
END
$$;

CREATE FUNCTION save_del_operation(in_value POINT, in_task_id INTEGER)
  RETURNS INTEGER
LANGUAGE plpgsql
AS $$
DECLARE
  current_op    INTEGER;
  pt_operations INTEGER [];
BEGIN

  SELECT operations
  INTO pt_operations
  FROM FPOINT3D
  WHERE value <-> in_value < 0.00001 AND task_id = in_task_id;

  EXECUTE 'SELECT last_value FROM f_operation_seq_for_task_' || in_task_id
  INTO current_op;

  IF NOT FOUND
  THEN
    INSERT INTO fpoint3d (task_id, value)
    VALUES (in_task_id, in_value);
  ELSE
    IF array_length(pt_operations, 1) % 2 = 1
    THEN
      current_op = increase_operations(in_value, in_task_id);
    END IF;
  END IF;

  RETURN current_op;
END
$$;

CREATE TYPE OPERATION_TYPE AS ENUM ('add', 'delete', 'nothing');
CREATE TYPE OPERATION AS (id INTEGER, "type" OPERATION_TYPE);

CREATE FUNCTION collect_operation(in_operations INTEGER [], in_from_operation INTEGER)
  RETURNS OPERATION
LANGUAGE plpgsql
AS $$
DECLARE
  in_operations_length  INTEGER = array_length(in_operations, 1);
  new_operations_length INTEGER;
  last_operation_index  INTEGER;
BEGIN
  new_operations_length := count_operations_since(in_operations, in_from_operation);
  last_operation_index := in_operations [in_operations_length];
  IF in_operations_length = 0
  THEN
    RETURN (last_operation_index, 'nothing'::OPERATION_TYPE);
  ELSIF new_operations_length % 2 = 0
    THEN
      RETURN (last_operation_index, 'nothing'::OPERATION_TYPE);
  ELSIF in_operations_length % 2 = 0
    THEN
      RETURN (last_operation_index, 'delete'::OPERATION_TYPE);
  ELSIF in_operations_length % 2 = 1
    THEN
      RETURN (last_operation_index, 'add'::OPERATION_TYPE);
  END IF;
  RETURN (last_operation_index, 'nothing'::OPERATION_TYPE);
END
$$;


-- TODO ameliorate performance using dichotomy and recursion
CREATE FUNCTION count_operations_since(in_array INTEGER [], in_value INTEGER)
  RETURNS INTEGER
LANGUAGE plpgsql
AS $$
DECLARE
  tmp_value INTEGER;
BEGIN
  FOREACH tmp_value IN ARRAY in_array
  LOOP
    IF tmp_value > in_value
    THEN
      RETURN array_length(in_array, 1) - array_position(in_array, tmp_value) + 1;
    END IF;
  END LOOP;
  RETURN 0;
END
$$;

CREATE FUNCTION empty_firefly_database()
  RETURNS VOID
LANGUAGE plpgsql
AS $$
DECLARE
  sequence_number INTEGER = currval('task_id_seq');
BEGIN
  FOR seq_id IN 0..sequence_number LOOP
    EXECUTE format('DROP SEQUENCE IF EXISTS f_operation_seq_for_task_%s', seq_id);
  END LOOP;
  TRUNCATE task, fpoint3d;
  ALTER SEQUENCE fpoint3d_id_seq RESTART WITH 0;
  ALTER SEQUENCE task_id_seq RESTART WITH 0;
END
$$;

CREATE TYPE OPERATION_WITH_ELEMENT AS (operation_id INTEGER, operation_type OPERATION_TYPE, point_id INTEGER, point_value POINT);

CREATE FUNCTION collect_operations(in_task_id INTEGER, in_from_operation INTEGER)
  RETURNS SETOF OPERATION_WITH_ELEMENT
LANGUAGE plpgsql
AS $$
DECLARE
  tmp_op     OPERATION;
  result_row OPERATION_WITH_ELEMENT;
  r          RECORD;
BEGIN
  FOR r IN SELECT
             id,
             "value",
             operations
           FROM fpoint3d
           WHERE task_id = in_task_id LOOP
    tmp_op := collect_operation(r.operations, in_from_operation);
    IF NOT tmp_op.type = 'nothing'
    THEN
      result_row := (tmp_op.id, tmp_op.type, r.id, r.value);
      RETURN NEXT result_row;
    END IF;

  END LOOP;
  RETURN;
END
$$;
