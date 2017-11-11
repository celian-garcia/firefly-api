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

-- Plan the tests.
SELECT plan(3);

-- Run the tests.
SELECT has_table( 'task', 'task table exists' );

SELECT is(pg_typeof(totalTasks()), 'integer', 'tasks count return integer');

SELECT is(totalTasks(), 1, 'tasks count is 1');

-- Finish the tests and clean up.
SELECT * FROM finish();
ROLLBACK;
