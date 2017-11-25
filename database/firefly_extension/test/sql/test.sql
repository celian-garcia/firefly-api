\unset ECHO
\i test/setup.sql

-- Plan the tests.
SELECT plan(1);

-- Run the tests.
SELECT has_table( 'task', 'task table exists' );

\i test/teardown.sql
