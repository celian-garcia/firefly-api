\set QUIET 1
-- Turn off echo and keep things quiet.

-- Format the output for nice TAP.
\pset format unaligned
\pset tuples_only true
\pset pager

-- Revert all changes on failure.
\set ON_ERROR_ROLLBACK 1
\set ON_ERROR_STOP true
\set QUIET 1

-- Load the TAP functions.
BEGIN;

-- ##### SQL code to test #####
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
-- ##############################

-- Plan the tests.
SELECT plan(11);

-- Run the tests.
SELECT lives_ok(
    'INSERT INTO
      task (name, description, type, module, state, "user", date)
      values('''', '''', 0, 0, 0, '''', '''');',
    'inserting a new task'
);

SELECT lives_ok(
    'INSERT INTO
      task (name, description, type, module, state, "user", date)
      values('''', '''', 0, 0, 0, '''', '''');',
    'inserting a new task'
);

SELECT lives_ok(
    'INSERT INTO
      fpoint3d (task_id, value)
      values(0, ''(0,0)'');',
    'inserting a new point'
);

SELECT lives_ok(
    'INSERT INTO
      fpoint3d (task_id, value)
      values(0, ''(1,1)'');',
    'inserting a new point'
);

SELECT lives_ok(
    'INSERT INTO
      fpoint3d (task_id, value)
      values(1, ''(0,0)'');',
    'inserting a new point'
);

SELECT results_eq(
    'SELECT id FROM task',
    ARRAY[0, 1],
    'tasks ids should be {0, 1}'
);

SELECT results_eq(
    'SELECT id FROM fpoint3d',
    ARRAY[0, 1, 2],
    'points id should be {0, 1, 2}'
);

SELECT results_eq(
    'SELECT id, task_id, operations FROM fpoint3d WHERE id = 0',
    $$VALUES (0, 0, ARRAY[1])$$,
    'first point data should be (0, 0, X, {1})'
);

SELECT results_eq(
    'SELECT id, task_id, operations FROM fpoint3d WHERE id = 1',
    $$VALUES (1, 0, ARRAY[2])$$,
    'second point data should be (1, 0, X, {2})'
);

SELECT results_eq(
    'SELECT id, task_id, operations FROM fpoint3d WHERE id = 2',
    $$VALUES (2, 1, ARRAY[1])$$,
    'third point data should be (2, 1, X, {1})'
);

SELECT sequences_are(
    'public',
    ARRAY[ 'fpoint3d_id_seq', 'task_id_seq', 'f_operation_seq_for_task_0', 'f_operation_seq_for_task_1']
);

-- Finish the tests and clean up.
SELECT *
FROM finish();
ROLLBACK;
ALTER SEQUENCE "fpoint3d_id_seq" RESTART WITH 0;
ALTER SEQUENCE "task_id_seq" RESTART WITH 0;
