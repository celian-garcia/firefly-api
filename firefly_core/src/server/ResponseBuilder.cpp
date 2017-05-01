// Copyright 2017 <Célian Garcia>

#include "firefly/core/server/ResponseBuilder.hpp"

namespace firefly {
    void ResponseBuilder::build(nlohmann::json json_content, std::shared_ptr<HttpResponse> response) {
        std::string content = json_content.dump();
        *response << "HTTP/1.1 200 \r\n";
        *response << "Access-Control-Allow-Origin: *\r\n";
        *response << "Access-Control-Allow-Methods: GET, POST, DELETE, PUT, PATCH, OPTIONS\r\n";
        *response << "Access-Control-Allow-Headers: Content-Type, api_key, Authorization\r\n";
        *response << "Content-Type: application/json\r\n";
        *response << "Content-Length: " << content.length() << "\r\n\r\n";
        *response << content;
    }
}

