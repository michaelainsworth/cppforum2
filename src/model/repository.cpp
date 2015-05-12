#include "model/repository.hpp"

repository::repository(soci::session& db) : db_(db) {}
