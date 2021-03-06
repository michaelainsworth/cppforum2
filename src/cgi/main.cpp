#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cppforum2/cppforum2.hpp>
#include "application.hpp"
#include <soci/soci.h>
#include <exception>
using namespace std;
using namespace soci;

int main() {

    try {
        config conf = config::load(std::getenv("CPPFORUM2_CONFIG"));

        session db(conf.database());
        repository repo(db, conf.schema());
        
        booster::cgix::cgi_gateway gw;
        application app(gw);
        app.run();

        return 0;
    } catch (std::system_error& e) {
        int code = e.code().value();
        cerr << "Error (" << code << "): " << e.what() << endl;
        return code;
    } catch (std::exception& e) {
        cerr << e.what() << endl;
        return -1;
    }
}
