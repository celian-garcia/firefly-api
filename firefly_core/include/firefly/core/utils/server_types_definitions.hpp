// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_SERVER_TYPES_DEFINITIONS_HPP
#define FIREFLY_SERVER_TYPES_DEFINITIONS_HPP
#include "lib/Simple-Web-Server-MODIFIED/simple_web_server/server_http.hpp"

typedef SimpleWeb::Server<SimpleWeb::HTTP> HttpServer;
typedef HttpServer::Response HttpResponse;
typedef HttpServer::Request HttpRequest;
#endif //FIREFLY_SERVER_TYPES_DEFINITIONS_HPP
