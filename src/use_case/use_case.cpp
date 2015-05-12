#include "use_case/use_case.hpp"

#include "model/repository.hpp"

use_case::use_case(repository& repo, soci::session& db, const std::string& usr_id) : repo_(repo), db_(db), tx_(repo_, db_), usr_id_(usr_id), usr_(nullptr) {

    usr_ = repo_.get<std::string, usr>(usr_id_);
    
}

use_case::~use_case() {}
