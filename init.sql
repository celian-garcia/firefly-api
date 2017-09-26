--
-- PostgreSQL database dump
--

-- Dumped from database version 9.6.1
-- Dumped by pg_dump version 9.6.1

-- Started on 2017-09-02 11:04:32

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SET check_function_bodies = false;
SET client_min_messages = warning;
SET row_security = off;

--
-- TOC entry 1 (class 3079 OID 12387)
-- Name: plpgsql; Type: EXTENSION; Schema: -; Owner:
--

CREATE EXTENSION IF NOT EXISTS plpgsql WITH SCHEMA pg_catalog;


--
-- TOC entry 2130 (class 0 OID 0)
-- Dependencies: 1
-- Name: EXTENSION plpgsql; Type: COMMENT; Schema: -; Owner:
--

COMMENT ON EXTENSION plpgsql IS 'PL/pgSQL procedural language';


SET search_path = public, pg_catalog;

--
-- TOC entry 186 (class 1259 OID 16451)
-- Name: task_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE task_id_seq
    START WITH 0
    INCREMENT BY 1
    MINVALUE 0
    NO MAXVALUE
    CACHE 1;


ALTER TABLE task_id_seq OWNER TO postgres;

SET default_tablespace = '';

SET default_with_oids = false;

--
-- TOC entry 185 (class 1259 OID 16431)
-- Name: task; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE task (
    id integer DEFAULT nextval('task_id_seq'::regclass) NOT NULL,
    name character varying(20) NOT NULL,
    description text NOT NULL,
    type integer,
    module integer,
    state integer,
    "user" character varying(20),
    date character varying(20)
);


ALTER TABLE task OWNER TO postgres;

----
---- TOC entry 2122 (class 0 OID 16431)
---- Dependencies: 185
---- Data for Name: task; Type: TABLE DATA; Schema: public; Owner: postgres
----
--
--COPY task (id, name, description, type, module, state, "user", date) FROM stdin;
--2	Default title	Default description 	0	0	0	celgarci	01/08/2013
--3	Default title	Default description		0	0	0	celgarci	01/08/2013
--4	Default title	Default description		0	0	0	celgarci	01/08/2013
--5	Default title	Default description		0	0	0	celgarci	01/08/2013
--6	Default title	Default description		0	0	0	celgarci	01/08/2013
--7	Default title	Default description		0	0	0	celgarci	01/08/2013
--8	Default title	Default description		0	0	0	celgarci	01/08/2013
--9	Default title	Default description		0	0	0	celgarci	01/08/2013
--10		Default title	Default description		0	0	0	celgarci	01/08/2013
--11		Default title	Default description		0	0	0	celgarci	01/08/2013
--12		Nouvelle tâche		Default description		1	0	0	celgarci	01/08/2013
--\.
--
--
----
---- TOC entry 2131 (class 0 OID 0)
---- Dependencies: 186
---- Name: task_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
----
--
--SELECT pg_catalog.setval('task_id_seq', 12, true);
INSERT INTO task (name, description, type, module, state, "user", date) VALUES
('Default title', 'Default description',0, 0, 0, 'celgarci', '01/08/2013');

--
-- TOC entry 2004 (class 2606 OID 16438)
-- Name: task task_id_key; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY task
    ADD CONSTRAINT task_id_key UNIQUE (id);


-- Completed on 2017-09-02 11:04:32

--
-- PostgreSQL database dump complete
--

