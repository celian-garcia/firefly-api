// Copyright 2017 <Célian Garcia>

#include <firefly/core/model/interpreters/PGResultInterpreter.hpp>
#include <regex>
#include <firefly/core/exception/FireflyException.hpp>

namespace firefly {
PGResultInterpreter::PGResultInterpreter(PGresult *result) : result(result) {
    this->registerProperties(PROPERTIES());
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
    str = str.substr(1, str.size() - 2);
    boost::algorithm::split(results, str, boost::algorithm::is_any_of(","));
    std::vector<int> int_results;
    std::transform(results.begin(), results.end(), std::back_inserter(int_results), [](const std::string &s) {
        return std::stoi(s);
    });
    return int_results;
}

template<>
cv::Vec3f PGResultInterpreter::get<cv::Vec3f>(const char *property_name, int position) {
    char *pt_str = this->get_value(property_name, position);
    std::string regex_str = "POINT Z \\((\\S+) (\\S+) (\\S+)\\)";
    std::regex regex(regex_str);
    std::cmatch m;    // same as std::match_results<const char*> cm;
    if (std::regex_match(pt_str, m, regex)) {
        cv::Vec3f result;
        for (unsigned i = 1; i < m.size(); ++i) {
            result[i - 1] = std::stof(m[i].str());
        }
        std::cout << result << std::endl;
        return result;

    } else {
        std::string err_message = "The PostGIS's Point Z : " + std::string(pt_str) +
                " do not match the regex " + regex_str;
        throw FireflyException(HtmlStatusCode::INTERNAL_SERVER_ERROR, err_message);
    }
}

char *PGResultInterpreter::get_value(const char *property_name, int position) {
    return PQgetvalue(this->result, position, this->f_numbers_map[property_name]);
}

int PGResultInterpreter::get_row_number() {
    return PQntuples(this->result);
}

const std::vector<const char *> PGResultInterpreter::PROPERTIES() {
    return {};
}

}  // namespace firefly
