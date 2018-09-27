/// Copyright 2017 <Célian Garcia>

#include <cpptoml.h>
#include <firefly/server/Server.hpp>
#include <firefly/config/ServerConfig.hpp>
#include <firefly/config/DatabaseConfig.hpp>

#ifdef WITH_FLY_MODULE

#include "fly_module/data/FlyModule.hpp"

#endif

#ifdef WITH_CV_MODULE
#include "cv_module/api/CvHandler.hpp"
#endif

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: Firefly.exe <toml_config>\n";
        return 1;
    }
    auto config = cpptoml::parse_file(argv[1]);

    // Read the server config
    auto port = config->get_qualified_as<int16_t>("server.port").value_or(8080);
    auto threads_count = config->get_qualified_as<int16_t>("server.threads_count").value_or(3);
    auto resources_path_raw = config->get_qualified_as<std::string>("server.resources").value_or("/srv/firefly/www");
    auto resources_path = boost::filesystem::canonical(resources_path_raw);
    firefly::ServerConfig server_config = { port, threads_count, resources_path };

    // Read the database config
    auto db_host = config->get_qualified_as<std::string>("database.host").value_or("localhost");
    auto db_port = config->get_qualified_as<int16_t>("database.port").value_or(5432);
    auto db_database = config->get_qualified_as<std::string>("database.database").value_or("firefly_hive");
    auto db_username = config->get_qualified_as<std::string>("database.username").value_or("postgres");
    auto db_password = config->get_qualified_as<std::string>("database.password").value_or("postgres");
    firefly::DatabaseConfig db_config = { db_host, db_port, db_database, db_username, db_password };

    firefly::DataCommonStore dataStore;
    firefly::Server server(server_config, db_config, dataStore);

#ifdef WITH_FLY_MODULE
    firefly::Module *module = new firefly::FlyModule();
    auto *flyThreadPool = new firefly::ThreadPool(threads_count);
    server.registerModule(module, flyThreadPool);
#endif
    std::cout << "Server successfully initialized\n" << std::endl;;

    server.run();

    return 0;
}
