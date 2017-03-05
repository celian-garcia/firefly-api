// Copyright 2017 <Célian Garcia>

#ifndef INCLUDE_FIREFLY_API_MAINHANDLER_HPP_
#define INCLUDE_FIREFLY_API_MAINHANDLER_HPP_
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <memory>
#include "firefly/utils/server_types_definitions.hpp"
#include "firefly/utils/ThreadPool.hpp"
#include "IModuleHandler.hpp"
#include "firefly/modules/fly/api/FlyHandler.hpp"
//#include "firefly/modules/opencv/api/OpencvFilterHandler.hpp"
#include "firefly/utils/FireflyException.hpp"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/thread/thread.hpp>
#include <boost/filesystem.hpp>

namespace firefly {
using boost::filesystem::path;

class MainHandler {
 public:
    MainHandler(HttpServer* server, const boost::filesystem::path& resources_path, int nb_threads);
 private:
    void initModulesResources();
    void initDefaultResource();
    void sendDefaultResource(
        const std::shared_ptr<HttpResponse> &response,
        const std::shared_ptr<std::ifstream> &ifs);
    ThreadPool* m_pool;
    HttpServer* m_server;
    path m_resources_path;
};

}  // end namespace firefly
#endif  // INCLUDE_FIREFLY_API_MAINHANDLER_HPP_
