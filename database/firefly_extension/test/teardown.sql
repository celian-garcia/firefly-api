-- Finish the tests and clean up.
SELECT *
FROM finish();
ROLLBACK;

-- To be sure that all is clean for the next test.
ALTER SEQUENCE fpoint3d_id_seq RESTART WITH 0;
ALTER SEQUENCE task_id_seq RESTART WITH 0;
