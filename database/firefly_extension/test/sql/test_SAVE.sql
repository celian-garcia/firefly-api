\unset ECHO
\i test/setup.sql

-- Plan the tests.
SELECT plan(17);

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
    ARRAY [0, 1],
    'tasks ids should be {0, 1}'
);

SELECT results_eq(
    'SELECT id FROM fpoint3d',
    ARRAY [0, 1, 2],
    'points id should be {0, 1, 2}'
);

SELECT results_eq(
    'SELECT id, task_id, value, operations FROM fpoint3d WHERE id = 0',
    $$VALUES (0, 0, POINT(0, 0), ARRAY[1])$$,
    'first point data should be (0, 0, (0, 0), {1})'
);

SELECT results_eq(
    'SELECT id, task_id, value, operations FROM fpoint3d WHERE id = 1',
    $$VALUES (1, 0, POINT(1, 1), ARRAY[2])$$,
    'second point data should be (1, 0, (1, 1), {2})'
);

SELECT results_eq(
    'SELECT id, task_id, value, operations FROM fpoint3d WHERE id = 2',
    $$VALUES (2, 1, POINT(0, 0), ARRAY[1])$$,
    'third point data should be (2, 1, (0, 0), {1})'
);

SELECT sequences_are(
    'public',
    ARRAY ['fpoint3d_id_seq', 'task_id_seq', 'f_operation_seq_for_task_0', 'f_operation_seq_for_task_1']
);

SELECT is(
    increase_operations(point(1, 1), 0),
    3,
    'Increasing second point operations should return 3');

SELECT results_eq(
    'SELECT id, task_id, value, operations FROM fpoint3d WHERE id = 1',
    $$VALUES (1, 0, POINT(1, 1), ARRAY[2, 3])$$,
    'second point data should now be (1, 0, (1, 1), {2, 3})'
);

SELECT is(
    save_add_operation(point(1, 1), 0),
    4,
    'Saving add operation on the first point should return state 4');

SELECT is(
    save_add_operation(point(1, 1), 0),
    4,
    'Saving another add operation on the first point should still return state 4');

SELECT is(
    save_del_operation(point(1, 1), 0),
    5,
    'Saving delete operation on the first point should return state 5');

SELECT is(
    save_del_operation(point(1, 1), 0),
    5,
    'Saving another delete operation on the first point should still return 5');

-- Finish the tests and clean up.
SELECT *
FROM finish();
ROLLBACK;
