--
-- PostgreSQL database dump
--

-- Dumped from database version 9.6.5
-- Dumped by pg_dump version 9.6.5

-- Started on 2017-10-29 14:49:51 CET

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SET check_function_bodies = false;
SET client_min_messages = warning;
SET row_security = off;

--
-- TOC entry 1 (class 3079 OID 12437)
-- Name: plpgsql; Type: EXTENSION; Schema: -; Owner: 
--

CREATE EXTENSION IF NOT EXISTS plpgsql WITH SCHEMA pg_catalog;


--
-- TOC entry 2191 (class 0 OID 0)
-- Dependencies: 1
-- Name: EXTENSION plpgsql; Type: COMMENT; Schema: -; Owner: 
--

COMMENT ON EXTENSION plpgsql IS 'PL/pgSQL procedural language';


SET search_path = public, pg_catalog;

--
-- TOC entry 187 (class 1259 OID 16407)
-- Name: fpoint3d_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE fpoint3d_id_seq
    START WITH 1
    INCREMENT BY 1
    MINVALUE 0
    NO MAXVALUE
    CACHE 1;


ALTER TABLE fpoint3d_id_seq OWNER TO postgres;

SET default_tablespace = '';

SET default_with_oids = false;

--
-- TOC entry 188 (class 1259 OID 16409)
-- Name: fpoint3d; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE fpoint3d (
    id integer DEFAULT nextval('fpoint3d_id_seq'::regclass) NOT NULL,
    task_id integer,
    value point NOT NULL,
    operations integer[] NOT NULL
);


ALTER TABLE fpoint3d OWNER TO postgres;

--
-- TOC entry 185 (class 1259 OID 16386)
-- Name: task_id_seq; Type: SEQUENCE; Schema: public; Owner: firefly_foreman
--

CREATE SEQUENCE task_id_seq
    START WITH 0
    INCREMENT BY 1
    MINVALUE 0
    NO MAXVALUE
    CACHE 1;


ALTER TABLE task_id_seq OWNER TO firefly_foreman;

--
-- TOC entry 186 (class 1259 OID 16388)
-- Name: task; Type: TABLE; Schema: public; Owner: firefly_foreman
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


ALTER TABLE task OWNER TO firefly_foreman;

--
-- TOC entry 2184 (class 0 OID 16409)
-- Dependencies: 188
-- Data for Name: fpoint3d; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY fpoint3d (id, task_id, value, operations) FROM stdin;
\.


--
-- TOC entry 2192 (class 0 OID 0)
-- Dependencies: 187
-- Name: fpoint3d_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('fpoint3d_id_seq', 0, true);


--
-- TOC entry 2182 (class 0 OID 16388)
-- Dependencies: 186
-- Data for Name: task; Type: TABLE DATA; Schema: public; Owner: firefly_foreman
--

COPY task (id, name, description, type, module, state, "user", date) FROM stdin;
0	Default title	Default description	0	0	0	celgarci	01/08/2013
\.


--
-- TOC entry 2193 (class 0 OID 0)
-- Dependencies: 185
-- Name: task_id_seq; Type: SEQUENCE SET; Schema: public; Owner: firefly_foreman
--

SELECT pg_catalog.setval('task_id_seq', 1, true);


--
-- TOC entry 2062 (class 2606 OID 24590)
-- Name: fpoint3d FPOINT3D_PRIMARY_KEY; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY fpoint3d
    ADD CONSTRAINT "FPOINT3D_PRIMARY_KEY" PRIMARY KEY (id);


--
-- TOC entry 2060 (class 2606 OID 16396)
-- Name: task task_id_key; Type: CONSTRAINT; Schema: public; Owner: firefly_foreman
--

ALTER TABLE ONLY task
    ADD CONSTRAINT task_id_key UNIQUE (id);


--
-- TOC entry 2063 (class 2606 OID 24591)
-- Name: fpoint3d FPOINT_3D_FOREIGN_KEY; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY fpoint3d
    ADD CONSTRAINT "FPOINT_3D_FOREIGN_KEY" FOREIGN KEY (task_id) REFERENCES task(id);


-- Completed on 2017-10-29 14:49:51 CET

--
-- PostgreSQL database dump complete
--

