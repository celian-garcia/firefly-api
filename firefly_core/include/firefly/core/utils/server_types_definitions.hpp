// Copyright 2017 <Célian Garcia>

#pragma once

#include "simple_web_server/server_http.hpp"

typedef SimpleWeb::ServerBase<SimpleWeb::HTTP> HttpServer;
typedef HttpServer::Response HttpResponse;
typedef HttpServer::Request HttpRequest;

