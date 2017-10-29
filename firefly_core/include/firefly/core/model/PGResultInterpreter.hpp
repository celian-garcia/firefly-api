// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_RESULTTRANSCRIVER_HPP
#define FIREFLY_RESULTTRANSCRIVER_HPP


#include <map>
#include <libpq-fe.h>
#include <functional>
#include <vector>
#include <cstring>

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

    private:

        char *get_value(const char *property_name, int position);

        std::map<const char *, int, StrComparator> f_numbers_map;
        PGresult *result;
    };

}
#endif //FIREFLY_RESULTTRANSCRIVER_HPP
