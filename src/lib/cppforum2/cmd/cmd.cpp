#include <cppforum2/cmd/cmd.hpp>

#include <cppforum2/model/repository.hpp>

cmd::cmd(repository& repo, soci::session& db, const std::string& usr_id) : repo_(repo), db_(db), tx_(repo_, db_), usr_id_(usr_id), usr_(nullptr) {

    usr_ = repo_.get<std::string, usr>(usr_id_);
    
}

cmd::~cmd() {}
