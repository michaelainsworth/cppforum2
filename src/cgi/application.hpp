#ifndef CPPFORUM2_APPLICATION_HPP_INCLUDED
#define CPPFORUM2_APPLICATION_HPP_INCLUDED

#include <booster/cgix/cgix.hpp>

class application : public booster::cgix::application {
public:
    
    application(booster::cgix::gateway& gw);
    
protected:
    
    void setup_routes();
    
    void connection_not_handled(booster::cgix::connection& con);
    
};

#endif // #ifndef CPPFORUM2_APPLICATION_HPP_INCLUDED