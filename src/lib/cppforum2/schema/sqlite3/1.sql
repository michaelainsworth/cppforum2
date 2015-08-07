-- -----------------------------------------------------------------------------
--
-- Filename: 1.sql
--
-- Description: This file is used to create the initial version of the
--              cppforum2 database for SQLite databases.
--
--              Statements are separated by a double-dash (--) followed by
--              a space then the keyword "SEPARATOR".
--
-- -----------------------------------------------------------------------------

create table if not exists opt
(
    opt_key integer not null primary key,
    opt_id character varying(126) not null,
    opt_value text not null,
    unique(opt_id)
);

-- SEPARATOR

create table if not exists usr
(
    usr_key integer not null primary key,
    usr_id character varying(126) not null,
    password_ character varying(126) not null,
    first_name character varying(126) not null,
    last_name character varying(126) not null,
    unique(usr_id)
);

-- SEPARATOR

create table if not exists forum
(
    forum_key integer not null primary key,
    forum_id character varying(126) not null,
    forum_name character varying(126) not null,
    description character varying(126) not null,
    unique(forum_id)
);
