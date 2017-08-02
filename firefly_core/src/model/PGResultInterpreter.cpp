// Copyright 2017 <Célian Garcia>

#include <vector>
#include <algorithm>
#include "firefly/core/model/PGResultInterpreter.hpp"

namespace firefly {
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

    char *PGResultInterpreter::get_value(const char *property_name, int position) {
        return PQgetvalue(this->result, position, this->f_numbers_map[property_name]);
    }

    int PGResultInterpreter::get_row_number() {
        return PQntuples(this->result);
    }
}