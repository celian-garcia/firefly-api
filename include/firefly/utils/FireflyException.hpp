// Copyright 2017 <Célian Garcia>

#ifndef INCLUDE_FIREFLY_UTILS_FIREFLYEXCEPTION_HPP_
#define INCLUDE_FIREFLY_UTILS_FIREFLYEXCEPTION_HPP_

#include <iostream>
#include <exception>
#include <string>
#include "firefly/utils/HtmlStatusCode.hpp"
#include "firefly/utils/server_types_definitions.hpp"

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
            *response << "HTTP/1.1 " << this->m_code << "\r\n";
            *response << "Content-Length: " << this->m_content.length() << "\r\n\r\n";
            *response << this->m_content;
        }

    private:
        HtmlStatusCode m_code;
        std::string m_content;
    };

}  // end namespace firefly
#endif  // INCLUDE_FIREFLY_UTILS_FIREFLYEXCEPTION_HPP_
