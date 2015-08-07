create table if not exists opt
(
    opt_key integer not null primary key,
    opt_id character varying(126) not null,
    opt_value text not null,
    unique(opt_id)
);
