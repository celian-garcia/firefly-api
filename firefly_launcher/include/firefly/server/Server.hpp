// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_LAUNCHER_INCLUDE_FIREFLY_SERVER_SERVER_HPP_
#define FIREFLY_LAUNCHER_INCLUDE_FIREFLY_SERVER_SERVER_HPP_

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <memory>
#include <map>
#include <thread>

#include <boost/filesystem.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/thread/thread.hpp>

#include <simple_web_server/server_http.hpp>

#include <firefly/core/utils/server_types_definitions.hpp>
#include <firefly/core/data/Module.hpp>
#include <firefly/core/data/Task.hpp>
#include <firefly/core/data/Operation.hpp>
#include <firefly/core/data/TaskBuilder.hpp>
#include <firefly/core/utils/ResponseBuilder.hpp>
#include <firefly/core/model/TaskModel.hpp>
#include <firefly/core/model/DatabaseManager.hpp>
#include <firefly/core/config/DataCommonStore.hpp>
#include <firefly/core/utils/ThreadPool.hpp>

#include <fly_module/workers/FlyCloudPopulation.hpp>

namespace firefly {

typedef SimpleWeb::Server<SimpleWeb::HTTP> HttpServer;

class Server {
 public:
    Server(unsigned short port, boost::filesystem::path resources_path, DataCommonStore dataStore);

    void registerModule(Module *module, ThreadPool *pool);

    void initializeFireflyResources();

    void run();

 private:
    HttpServer server;
    boost::filesystem::path resources_path;
    DataCommonStore dataStore;
    std::map<int, firefly::ThreadPool *> thread_pool_map;

    void sendDefaultResource(const std::shared_ptr<HttpServer::Response> &response,
                             const std::shared_ptr<std::ifstream> &ifs);

    void initDefaultResource();

    std::function<void(std::shared_ptr<HttpResponse>, std::shared_ptr<HttpRequest>)> static buildFireflyResource(
            const std::function<void(std::shared_ptr<HttpResponse>, std::shared_ptr<HttpRequest>)> &resource);
};

}  // namespace firefly

#endif  // FIREFLY_LAUNCHER_INCLUDE_FIREFLY_SERVER_SERVER_HPP_
