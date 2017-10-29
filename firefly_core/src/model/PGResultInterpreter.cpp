// Copyright 2017 <Célian Garcia>

#include <vector>
#include <algorithm>
#include <cxcore.h>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "firefly/core/model/PGResultInterpreter.hpp"
#include "libpqtypes.h"

namespace firefly {
    struct str2int { int operator ()( std::string value ) const { return atoi(value.c_str()); } };

    PGResultInterpreter::PGResultInterpreter(PGresult *result) : result(result) {
    }

    void PGResultInterpreter::registerProperty(const char *property_name) {
        this->f_numbers_map[property_name] = PQfnumber(this->result, property_name);
    }

    void PGResultInterpreter::registerProperties(std::vector<const char *> property_names) {
        std::for_each(property_names.begin(), property_names.end(),
                      [this](const char *p_name) { this->registerProperty(p_name); });
    }

    template<>
    int PGResultInterpreter::get<int>(const char *property_name, int position) {
        return atoi(get_value(property_name, position));
    }

    template<>
    char *PGResultInterpreter::get<char *>(const char *property_name, int position) {
        return get_value(property_name, position);
    }

    template<>
    std::string PGResultInterpreter::get<std::string>(const char *property_name, int position) {
        return static_cast<std::string>(get_value(property_name, position));
    }

    template<>
    std::vector<int> PGResultInterpreter::get<std::vector<int>>(const char *property_name, int position) {
        std::string str = this->get<std::string>(property_name, position);
        std::vector<std::string> results;
        str = str.substr(1, str.size()-2);
        boost::algorithm::split(results, str, boost::algorithm::is_any_of(","));
        std::vector<int> int_results;
        std::transform( results.begin(), results.end(), std::back_inserter(int_results), [] (const std::string& s) {
            return std::stoi(s);
        } );
        return int_results;
    }

    template<>
    cv::Vec3f PGResultInterpreter::get<cv::Vec3f>(const char *property_name, int position) {
        PGpoint pt;
        PQgetf(this->result, position, "%point", this->f_numbers_map[property_name], &pt);
        cv::Vec3f point((float)pt.x, (float)pt.y);
        return point;
    }

    char *PGResultInterpreter::get_value(const char *property_name, int position) {
        return PQgetvalue(this->result, position, this->f_numbers_map[property_name]);
    }

    int PGResultInterpreter::get_row_number() {
        return PQntuples(this->result);
    }
}