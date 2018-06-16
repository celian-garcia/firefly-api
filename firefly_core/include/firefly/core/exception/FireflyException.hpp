// Copyright 2017 <Célian Garcia>

#pragma once

#include <iostream>
#include <exception>
#include <string>

#include <json/json.hpp>

#include "firefly/core/utils/HtmlStatusCode.hpp"
#include "firefly/core/utils/server_types_definitions.hpp"
#include "firefly/core/data/Operation.hpp"
#include "firefly/core/utils/ResponseBuilder.hpp"

namespace firefly {

class FireflyException : public std::exception {
 public:
    FireflyException() = default;

    FireflyException(const HtmlStatusCode code, const std::string &content) :
            m_code(code), m_content(content) {}

    virtual const char *what() const throw() {
        return this->m_content.c_str();
    }

    void sendError(std::shared_ptr<HttpResponse> response) const {
        nlohmann::json content;
        content["code"] = this->m_code;
        content["message"] = this->m_content;

        ResponseBuilder::build(content, response);
    }

 private:
    HtmlStatusCode m_code;
    std::string m_content;
};

}  // namespace firefly

