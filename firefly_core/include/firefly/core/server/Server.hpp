// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_SERVER_HPP
#define FIREFLY_SERVER_HPP

#include <simple_web_server/server_http.hpp>
#include <boost/filesystem.hpp>
#include "firefly/core/utils/server_types_definitions.hpp"
#include "firefly/core/data/ProcessingAction.hpp"
#include "firefly/core/data/Module.hpp"
#include "firefly/core/data/Processing.hpp"

namespace firefly {
    typedef SimpleWeb::Server<SimpleWeb::HTTP> HttpServer;

    class Server {
    public:

        Server(unsigned short port, boost::filesystem::path resources_path);

        void registerModule(Module module);

        void initializeFireflyResources();

        void initializeModuleResources(Module module);

        void registerProcessingAction(std::string procUri, ProcessingAction resource);

        void run();

    private:
        HttpServer server;
        std::vector<Module> modules_list;
        boost::filesystem::path resources_path;

//        static const char *API_VERSION = "1";

        static std::string buildFireflyApiEndpoint();

        static std::string buildModuleApiEndpoint(Module module);

//        static std::string buildProcessingUri(std::string moduleApiEndpoint, Processing processing);

        void initializeResource(ProcessingAction processingAction);

        void sendDefaultResource(const std::shared_ptr<HttpResponse> &response, const std::shared_ptr<std::ifstream> &ifs);

        void initDefaultResource();
    };
}


#endif //FIREFLY_SERVER_HPP
