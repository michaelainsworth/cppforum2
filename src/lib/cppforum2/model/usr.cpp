#include "model/usr.hpp"

#include "model/repository.hpp"

usr::usr(repository& repo, key_t usr_key, const std::string& usr_id, const std::string& first_name, const std::string& last_name, bool is_admin) : repo_(repo), usr_key_(usr_key), usr_id_(usr_id), first_name_(first_name), last_name_(last_name), is_admin_(is_admin) {
    
}

bool usr::is_admin() const {
    return is_admin_;
}