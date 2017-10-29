// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_QUERYSTRING_HPP
#define FIREFLY_QUERYSTRING_HPP

#include <string>
#include <map>
#include <boost/algorithm/string.hpp>
#include <boost/regex.hpp>
#include "FireflyException.hpp"

namespace firefly {

    class QueryParameters {
    public:
        QueryParameters(const std::string &path) {
            if (path[0] != '?' || path.size() == 1)
                throw FireflyException(HtmlStatusCode::BAD_REQUEST, "Error parsing query string.");

            std::vector<std::string> parameters;
            boost::split(parameters, path, boost::is_any_of("&"));
            parameters[0].erase(0, 1); // Remove the interrogation point from first parameter
            for (auto param : parameters) {
                std::vector<std::string> param_vector;
                boost::split(param_vector, param, boost::is_any_of("="));
                if (param_vector.size() != 2)
                    throw FireflyException(HtmlStatusCode::BAD_REQUEST, "Error parsing query string.");

                this->values[param_vector[0]] = param_vector[1];
            }
        }

        std::string operator[] (std::string key) const {
            return this->values.at(key);
        }

        std::string& operator[](const std::string& key)
        {
            return this->values[key];
        }

    private:
        std::map<std::string, std::string> values;
    };

}

#endif //FIREFLY_QUERYSTRING_HPP
