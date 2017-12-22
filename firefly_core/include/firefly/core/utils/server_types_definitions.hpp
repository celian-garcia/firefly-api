// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_CORE_INCLUDE_FIREFLY_CORE_UTILS_SERVER_TYPES_DEFINITIONS_HPP_
#define FIREFLY_CORE_INCLUDE_FIREFLY_CORE_UTILS_SERVER_TYPES_DEFINITIONS_HPP_

#include "simple_web_server/server_http.hpp"

typedef SimpleWeb::ServerBase<SimpleWeb::HTTP> HttpServer;
typedef HttpServer::Response HttpResponse;
typedef HttpServer::Request HttpRequest;

#endif  // FIREFLY_CORE_INCLUDE_FIREFLY_CORE_UTILS_SERVER_TYPES_DEFINITIONS_HPP_
