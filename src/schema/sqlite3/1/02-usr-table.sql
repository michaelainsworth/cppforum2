create table if not exists usr
(
    usr_key integer not null primary key,
    usr_id character varying(126) not null,
    password_ character varying(126) not null,
    first_name character varying(126) not null,
    last_name character varying(126) not null,
    unique(usr_id)
);
