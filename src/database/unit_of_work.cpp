#include "database/unit_of_work.hpp"

unit_of_work::unit_of_work(repository& repo, soci::session& db) : repo_(repo), db_(db) {}

unit_of_work::~unit_of_work() {
    if (is_in_transaction()) {
        rollback();
    }
}

bool unit_of_work::is_in_transaction() {
    // TODO: Finish
    return false;
}

void unit_of_work::commit() {
    // TODO: Finish
}

void unit_of_work::rollback() {
    // TODO: Finish
}

