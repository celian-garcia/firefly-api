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
  operations INTEGER []                                             NOT NULL
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

CREATE FUNCTION fill_in_operation_seq()
  RETURNS TRIGGER
LANGUAGE plpgsql
AS $$
DECLARE
  current_op INTEGER := nextval('f_operation_seq_for_task_' || NEW.task_id);
BEGIN
  NEW.operations := NEW.operations || current_op;
  RETURN NEW;
END
$$;

CREATE TRIGGER fill_in_operation_seq
BEFORE INSERT ON fpoint3d
FOR EACH ROW EXECUTE PROCEDURE fill_in_operation_seq();

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

  EXECUTE 'SELECT last_value FROM f_operation_seq_for_task_' || in_task_id INTO current_op;

  IF NOT FOUND
  THEN
    INSERT INTO fpoint3d (task_id, value)
    VALUES (in_task_id, in_value);
  ELSE
    IF array_length(pt_operations, 1) % 2 = 0
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

  EXECUTE 'SELECT last_value FROM f_operation_seq_for_task_' || in_task_id INTO current_op;

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