\unset ECHO
\i test/setup.sql
\i test/scripts/fill_data.sql

DO $$ BEGIN
  PERFORM save_add_operation(point(0, 0), 0);
  PERFORM save_del_operation(point(0, 0), 0);
  PERFORM save_add_operation(point(0, 0), 0);

  PERFORM save_add_operation(point(1, 1), 0);
  PERFORM save_del_operation(point(1, 1), 0);
  PERFORM save_add_operation(point(1, 1), 0);
  PERFORM save_del_operation(point(1, 1), 0);
END $$;

CREATE TYPE OPERATION AS (op_type OPERATION_TYPE, pt_id INTEGER, pt_value POINT);

CREATE FUNCTION collect_operations(in_task_id INTEGER, in_from_operation INTEGER)
  RETURNS SETOF OPERATION
LANGUAGE plpgsql
AS $$
DECLARE
  tmp_op_type OPERATION_TYPE;
  tmp_op      OPERATION;
  r           RECORD;
BEGIN
  FOR r IN SELECT
             id,
             "value",
             operations
           FROM fpoint3d
           WHERE task_id = in_task_id LOOP
    tmp_op_type := collect_operation(r.operations, in_from_operation);
    IF NOT tmp_op_type = 'nothing'
    THEN
      tmp_op := (tmp_op_type, r.id, r.value);
      RETURN NEXT tmp_op;
    END IF;

  END LOOP;
  RETURN;
END
$$;

-- Plan the tests.
SELECT plan(16);

-- Run the tests.
-- "count_operations_since" function tests
SELECT is(
    count_operations_since(ARRAY [1, 3, 4], 3),
    1,
    'There is 1 operation since operation 3 in the array {1, 3, 4}');
SELECT is(
    count_operations_since(ARRAY [1, 3, 4], 2),
    2,
    'There are 2 operations since operation 2 in the array {1, 3, 4}');
SELECT is(
    count_operations_since(ARRAY [1], 2),
    0,
    'There is no operation since operation 2 in the array {1}');
SELECT is(
    count_operations_since(ARRAY [1, 5], 6),
    0,
    'There is no operation since operation 6 in the array {1, 5}');
SELECT is(
    count_operations_since(ARRAY [5], 4),
    1,
    'There is 1 operation since operation 4 in the array {5}');
SELECT is(
    count_operations_since(ARRAY [] :: INTEGER [], 4),
    0,
    'There is no operation since operation 4 in an empty array');
SELECT is(
    count_operations_since(ARRAY [1, 2, 3], 0),
    3,
    'There is 3 operation since operation 0 in the array {1, 2, 3}');

-- "collect_operation" function tests
SELECT is(
    collect_operation(ARRAY [1, 2, 3], 2),
    'add',
    'Collect on {1, 2, 3} with last operation==2 should return ''add'' operation');
SELECT is(
    collect_operation(ARRAY [1, 2, 3, 4], 2),
    'nothing',
    'Collect on {1, 2, 3, 4} with last operation==2 should return ''nothing'' operation');
SELECT is(
    collect_operation(ARRAY [1, 3, 4], 3),
    'add',
    'Collect on {1, 3, 4} with last operation==3 should return ''add'' operation');
SELECT is(
    collect_operation(ARRAY [3, 4], 3),
    'delete',
    'Collect on {3, 4} with last operation==3 should return ''delete'' operation');
SELECT is(
    collect_operation(ARRAY [1, 3, 4], 2),
    'nothing',
    'Collect on {1, 3, 4} with last operation==2 should return ''nothing'' operation');
SELECT is(
    collect_operation(ARRAY [1, 2, 3], 0),
    'add',
    'Collect on {1, 2, 3} with last operation==0 should return ''add'' operation');

-- "collect_operations" function tests
SELECT results_eq(
    'SELECT * FROM collect_operations(0, 0)',
    $$ VALUES ('add' :: OPERATION_TYPE, 0, POINT(0, 0)) $$,
    'Collect operations of task 0 since operation 0 should return an add of point 0');

SELECT results_eq(
    'SELECT * FROM collect_operations(0, 4)',
    $$ VALUES ('delete'::OPERATION_TYPE, 1, POINT(1, 1)) $$,
    'Collect operations of task 0 since operation 0 should return a delete of point 1');

SELECT is_empty(
    'SELECT * FROM collect_operations(0, 3)',
    'Collect operations of task 0 since operation 0 should return no operation');

\i test/teardown.sql