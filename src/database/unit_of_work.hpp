#ifndef CPPFORUM2_UNIT_OF_WORK_HPP_INCLUDED
#define CPPFORUM2_UNIT_OF_WORK_HPP_INCLUDED

class repository;

namespace soci {
    class session;
}

class unit_of_work {
public:
    
    unit_of_work(repository& repo, soci::session& db);
    ~unit_of_work();
    
    bool is_in_transaction();
    void commit();
    void rollback();
    
    template<typename T>
    void save(T& t){}
    
    template<typename T>
    void delete_(T& t){}
    
private:
    
    repository& repo_;
    soci::session& db_;
    
};

#endif // #ifndef CPPFORUM2_UNIT_OF_WORK_HPP_INCLUDED