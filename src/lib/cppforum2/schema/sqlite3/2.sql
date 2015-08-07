-- -----------------------------------------------------------------------------
--
-- Filename: 2.sql
--
-- Description: This file is used to update the SQLite version of the
--              cppforum2 database. It inserts some initial data into the tables.
--
--              Statements are separated by a double-dash (--) followed by
--              a space then the keyword "SEPARATOR".
--
-- -----------------------------------------------------------------------------

insert into forum (forum_id, forum_name, description) values ("general", "General Discussion", "This is a forum for general discussion, created by the installation process.");

