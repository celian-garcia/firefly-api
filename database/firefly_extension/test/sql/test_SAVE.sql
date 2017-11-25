\unset ECHO
\i test/setup.sql
\i test/scripts/fill_data.sql

-- Plan the tests.
SELECT plan(16);

-- Run the tests.
SELECT results_eq(
    'SELECT id FROM task',
    ARRAY [0, 1, 2],
    'tasks ids should be {0, 1, 2}'
);

SELECT results_eq(
    'SELECT id FROM fpoint3d',
    ARRAY [0, 1, 2, 3],
    'points id should be {0, 1, 2, 3}'
);

SELECT results_eq(
    'SELECT id, task_id, value, operations FROM fpoint3d WHERE id = 0',
    $$VALUES (0, 0, POINT(0, 0), ARRAY[]::integer[])$$,
    'first point data should be (0, 0, (0, 0), {})'
);

SELECT results_eq(
    'SELECT id, task_id, value, operations FROM fpoint3d WHERE id = 1',
    $$VALUES (1, 0, POINT(1, 1), ARRAY[]::integer[])$$,
    'second point data should be (1, 0, (1, 1), {})'
);

SELECT results_eq(
    'SELECT id, task_id, value, operations FROM fpoint3d WHERE id = 2',
    $$VALUES (2, 1, POINT(0, 0), ARRAY[]::integer[])$$,
    'third point data should be (2, 1, (0, 0), {})'
);

SELECT results_eq(
    'SELECT id, task_id, value, operations FROM fpoint3d WHERE id = 3',
    $$VALUES (3, 2, POINT(0, 0), ARRAY[]::integer[])$$,
    'fourth point data should be (3, 2, (0, 0), {})'
);

SELECT sequences_are(
    'public',
    ARRAY [
    'fpoint3d_id_seq', 'task_id_seq', 'f_operation_seq_for_task_0', 'f_operation_seq_for_task_1',
    'f_operation_seq_for_task_2']
);

SELECT is(
    increase_operations(point(1, 1), 0),
    1,
    'Increasing second point operations should return 1');

SELECT results_eq(
    'SELECT id, task_id, value, operations FROM fpoint3d WHERE id = 1',
    $$VALUES (1, 0, POINT(1, 1), ARRAY[1])$$,
    'second point data should now be (1, 0, (1, 1), {1})'
);

SELECT is(
    save_add_operation(point(0, 0), 0),
    2,
    'Saving add operation on the first point should return state 2');

SELECT results_eq(
    'SELECT id, task_id, value, operations FROM fpoint3d WHERE id = 0',
    $$VALUES (0, 0, POINT(0, 0), ARRAY[2])$$,
    'first point data should now be (0, 0, (0, 0), {2})'
);

SELECT is(
    save_add_operation(point(0, 0), 0),
    2,
    'Saving another add operation on the first point should still return state 2');

SELECT is(
    save_del_operation(point(0, 0), 0),
    3,
    'Saving delete operation on the first point should return state 3');

SELECT is(
    save_del_operation(point(0, 0), 0),
    3,
    'Saving another delete operation on the first point should still return 3');

SELECT is(
    save_add_operation(point(0, 0), 1),
    1,
    'Saving add operation on the third point should return 1');

SELECT is(
    save_del_operation(point(0, 0), 2),
    1,
    'Saving del operation on the fourth point should return 1');

\i test/teardown.sql
