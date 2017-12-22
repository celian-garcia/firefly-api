// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_CORE_INCLUDE_FIREFLY_CORE_MODEL_INTERPRETERS_PGRESULTINTERPRETER_HPP_
#define FIREFLY_CORE_INCLUDE_FIREFLY_CORE_MODEL_INTERPRETERS_PGRESULTINTERPRETER_HPP_

#include <cxcore.h>
#include <libpq-fe.h>
#include <libpqtypes.h>
#include <map>
#include <functional>
#include <vector>
#include <cstring>
#include <iostream>
#include <boost/algorithm/string.hpp>

namespace firefly {
struct StrComparator : public std::binary_function<const char *, const char *, bool> {
 public:
    bool operator()(const char *str1, const char *str2) const { return std::strcmp(str1, str2) < 0; }
};

class PGResultInterpreter {
 public:
    explicit PGResultInterpreter(PGresult *result);

    void registerProperty(const char *property_name);

    void registerProperties(std::vector<const char *> property_names);

    int get_row_number();

    template<class T>
    T get(const char *property_name, int position);

    virtual const std::vector<const char *> PROPERTIES();

 private:
    char *get_value(const char *property_name, int position);

    std::map<const char *, int, StrComparator> f_numbers_map;
    PGresult *result;
};
}  // namespace firefly

#endif  // FIREFLY_CORE_INCLUDE_FIREFLY_CORE_MODEL_INTERPRETERS_PGRESULTINTERPRETER_HPP_
