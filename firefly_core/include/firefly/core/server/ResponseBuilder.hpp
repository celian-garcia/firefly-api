// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_RESPONSE_HPP
#define FIREFLY_RESPONSE_HPP

#include "json/json.hpp"
#include "firefly/core/utils/server_types_definitions.hpp"

namespace firefly {
    class ResponseBuilder {
    public:
        static void build(nlohmann::json content, std::shared_ptr<HttpResponse> response);
        static void build(std::string content, std::shared_ptr<HttpResponse> response);
    };
}

#endif //FIREFLY_RESPONSE_HPP
