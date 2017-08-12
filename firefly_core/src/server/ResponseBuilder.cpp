// Copyright 2017 <Célian Garcia>

#include <firefly/core/utils/Operation.hpp>
#include "firefly/core/server/ResponseBuilder.hpp"

namespace firefly {

    void ResponseBuilder::build(const char *raw_content, std::shared_ptr<HttpResponse> response) {
        ResponseBuilder::build(std::string(raw_content), std::move(response));
    }

    void ResponseBuilder::build(std::string raw_content, std::shared_ptr<HttpResponse> response) {
        *response << "HTTP/1.1 200 \r\n";
        *response << "Content-Type: application/json\r\n";
        *response << "Content-Length: " << raw_content.length() << "\r\n\r\n";
        *response << raw_content;
    }

    void ResponseBuilder::build(nlohmann::json raw_content, std::shared_ptr<HttpResponse> response) {
        ResponseBuilder::build(raw_content.dump(), std::move(response));
    }
}

