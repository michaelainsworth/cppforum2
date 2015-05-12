create table opts
(
    opt_key serial not null primary key,
    opt_id character varying(126) not null,
    opt_value text not null,
    unique(opt_id)
);

insert into opts (opt_id, opt_value) values ( "database_version", "1") ;

create table usr
(
    usr_key serial not null primary key,
    usr_id character varying(126) not null,
    password_ character varying(126) not null,
    first_name character varying(126) not null,
    last_name character varying(126) not null,
    unique(usr_id)
);

create table forum
(
    forum_key serial not null primary key,
    forum_id character varying(126) not null,
    forum_name character varying(126) not null,
    description character varying(126) not null,
    unique(forum_id)
);

