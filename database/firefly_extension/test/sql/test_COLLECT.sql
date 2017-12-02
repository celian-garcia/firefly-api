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
    ROW (3, 'add' :: OPERATION_TYPE) :: OPERATION,
    'Collect on {1, 2, 3} with last operation==2 should return (3, ''add'') operation');
SELECT is(
    collect_operation(ARRAY [1, 2, 3, 4], 2),
    ROW (4, 'nothing' :: OPERATION_TYPE) :: OPERATION,
    'Collect on {1, 2, 3, 4} with last operation==2 should return (4, ''nothing'') operation');
SELECT is(
    collect_operation(ARRAY [1, 3, 4], 3),
    ROW(4, 'add':: OPERATION_TYPE) :: OPERATION,
    'Collect on {1, 3, 4} with last operation==3 should return (4, ''add'') operation');
SELECT is(
    collect_operation(ARRAY [3, 4], 3),
    ROW(4, 'delete':: OPERATION_TYPE) :: OPERATION,
    'Collect on {3, 4} with last operation==3 should return (4, ''delete'') operation');
SELECT is(
    collect_operation(ARRAY [1, 3, 4], 2),
    ROW(4, 'nothing':: OPERATION_TYPE) :: OPERATION,
    'Collect on {1, 3, 4} with last operation==2 should return (4, ''nothing'') operation');
SELECT is(
    collect_operation(ARRAY [1, 2, 3], 0),
    ROW(3, 'add':: OPERATION_TYPE) :: OPERATION,
    'Collect on {1, 2, 3} with last operation==0 should return (3, ''add'') operation');

-- "collect_operations" function tests
SELECT results_eq(
    'SELECT * FROM collect_operations(0, 0)',
    $$ VALUES (3, 'add'::OPERATION_TYPE, 0, POINT(0, 0)) $$,
    'Collect operations of task 0 since operation 0 should return an add of point 0');

SELECT results_eq(
    'SELECT * FROM collect_operations(0, 4)',
    $$ VALUES (7, 'delete'::OPERATION_TYPE, 1, POINT(1, 1)) $$,
    'Collect operations of task 0 since operation 4 should return a delete of point 1');

SELECT is_empty(
    'SELECT * FROM collect_operations(0, 3)',
    'Collect operations of task 0 since operation 3 should return no operation');

\i test/teardown.sql