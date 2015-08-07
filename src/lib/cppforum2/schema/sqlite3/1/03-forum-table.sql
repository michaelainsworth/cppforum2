create table if not exists forum
(
    forum_key integer not null primary key,
    forum_id character varying(126) not null,
    forum_name character varying(126) not null,
    description character varying(126) not null,
    unique(forum_id)
);
