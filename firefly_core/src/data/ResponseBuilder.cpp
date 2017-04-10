// Copyright 2017 <Célian Garcia>

#include "firefly/core/data/ResponseBuilder.hpp"

namespace firefly {
    void ResponseBuilder::build(nlohmann::json json_content, std::shared_ptr<HttpResponse> response) {
        std::string content = json_content.dump();
        *response << "HTTP/1.1 200 \r\n";
        *response << "Content-Length: " << content.length() << "\r\n\r\n";
        *response << content;
    }
}

