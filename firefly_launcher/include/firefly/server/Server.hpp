// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_SERVER_HPP
#define FIREFLY_SERVER_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <memory>

#include <boost/filesystem.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/thread/thread.hpp>

#include <simple_web_server/server_http.hpp>

#include "firefly/core/utils/server_types_definitions.hpp"
#include "firefly/core/data/ProcessingAction.hpp"
#include "firefly/core/data/Module.hpp"
#include "firefly/core/data/Task.hpp"
#include <firefly/core/data/Operation.hpp>
#include <firefly/core/utils/server_types_definitions.hpp>
#include <firefly/core/utils/QueryParameters.hpp>
#include "firefly/core/utils/ResponseBuilder.hpp"
#include <firefly/core/model/TaskModel.hpp>
#include <firefly/core/data/TaskBuilder.hpp>

#include <firefly/core/model/DatabaseManager.hpp>
#include <firefly/core/config/DataCommonStore.hpp>

#include <optional>
#include <firefly/core/utils/ThreadPool.hpp>

namespace firefly {
    typedef SimpleWeb::Server<SimpleWeb::HTTP> HttpServer;

    class Server {
    public:

        Server(unsigned short port, boost::filesystem::path resources_path, DataCommonStore dataStore);

        void registerModule(Module& module, ThreadPool* pool);

        void initializeFireflyResources();

        void run();

    private:
        HttpServer server;
        boost::filesystem::path resources_path;
        DataCommonStore dataStore;
        std::map<int, firefly::ThreadPool*> thread_pool_map;

        void sendDefaultResource(const std::shared_ptr<HttpServer::Response> &response, const std::shared_ptr<std::ifstream> &ifs);

        void initDefaultResource();

        std::function<void(std::shared_ptr<HttpResponse>, std::shared_ptr<HttpRequest>)> static buildFireflyResource(
                const std::function<void(std::shared_ptr<HttpResponse>, std::shared_ptr<HttpRequest>)>& resource);

    };
}


#endif //FIREFLY_SERVER_HPP
