// Copyright 2017 <Célian Garcia>

#ifndef INCLUDE_FIREFLY_API_ABSTRACTHANDLER_HPP_
#define INCLUDE_FIREFLY_API_ABSTRACTHANDLER_HPP_

#include "../../../../lib/Simple-Web-Server-MODIFIED/simple_web_server/server_http.hpp"
#include "include/firefly/utils/server_types_definitions.hpp"

namespace firefly {

    class IModuleHandler {
    public:
        virtual void handleRequest(std::shared_ptr<HttpResponse> response, std::shared_ptr<HttpRequest> request) = 0;
    };

}  // end namespace firefly
#endif  // INCLUDE_FIREFLY_API_ABSTRACTHANDLER_HPP_
