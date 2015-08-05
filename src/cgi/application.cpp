#include "application.hpp"
using booster::cgix::connection;
using booster::cgix::request;
using booster::cgix::response;
using booster::cgix::cookie;

application::application(booster::cgix::gateway& gw) : booster::cgix::application(gw) {}

void application::setup_routes() {
    on("GET", "/test", [](booster::cgix::connection& con) {
        booster::cgix::response& resp = con.response();
        
        resp << response::ok;
        resp << booster::cgix::cookie("some_cookie", "1234");
        std::ostream& os = resp.out();
        os << "This is it!";
    });
}

void application::connection_not_handled(booster::cgix::connection& con) {
    booster::cgix::response& resp = con.response();
    
    resp << response::ok;
    resp << booster::cgix::cookie("some_cookie", "1234");
    std::ostream& os = resp.out();
    os << "NOT HANDLED";
}
