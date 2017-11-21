\unset ECHO
\i test/setup.sql

CREATE EXTENSION pgtap;

CREATE TYPE OPERATION_TYPE AS ENUM ('add', 'delete', 'nothing');

CREATE FUNCTION collect_operation(in_operations INTEGER [], in_from_operation INTEGER)
  RETURNS OPERATION_TYPE
LANGUAGE plpgsql
AS $$
DECLARE
  in_operations_length  INTEGER = array_length(in_operations, 1);
  new_operations_length INTEGER;
BEGIN
  new_operations_length := count_operations_since(in_operations, in_from_operation);
  IF new_operations_length = in_operations_length
  THEN
    RETURN 'nothing';
  ELSIF in_operations_length = 0
  THEN
    RETURN 'nothing';
  ELSIF new_operations_length % 2 = 0
    THEN
      RETURN 'nothing';
  ELSIF in_operations_length % 2 = 0
    THEN
      RETURN 'delete';
  ELSIF in_operations_length % 2 = 1
    THEN
      RETURN 'add';
  END IF;
  RETURN 'nothing';
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

-- CREATE FUNCTION collect_operations(in_task_id INTEGER, in_from_operation INTEGER)
--   RETURNS INTEGER
-- LANGUAGE plpgsql
-- AS $$
-- DECLARE
--   operations    INTEGER;
--   pt_operations INTEGER [];
-- BEGIN
--
--   SELECT operations
--   INTO pt_operations
--   FROM FPOINT3D
--   WHERE value <-> in_value < 0.00001 AND task_id = in_task_id;
--
--   EXECUTE 'SELECT last_value FROM f_operation_seq_for_task_' || in_task_id
--   INTO current_op;
--
--   IF NOT FOUND
--   THEN
--     INSERT INTO fpoint3d (task_id, value)
--     VALUES (in_task_id, in_value);
--     current_op = increase_operations(in_value, in_task_id);
--   ELSE
--     IF coalesce(array_length(pt_operations, 1), 0) % 2 = 0
--     THEN
--       current_op = increase_operations(in_value, in_task_id);
--     END IF;
--   END IF;
--
--   RETURN current_op;
-- END
-- $$;

-- Plan the tests.
SELECT plan(1);

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


-- Finish the tests and clean up.
SELECT *
FROM finish();
ROLLBACK;
