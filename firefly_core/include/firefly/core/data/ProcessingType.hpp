// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_PROCESSINGTYPE_HPP
#define FIREFLY_PROCESSINGTYPE_HPP

#include <string>
#include <vector>
#include <json/json.hpp>

namespace firefly {

    class ProcessingType {
    public:
        ProcessingType(const std::string &name, const std::vector<std::string> &aliases);

        const std::string &getName() const;

        const std::vector<std::string> &getAliases() const;

        const std::string &getId() const;

    private:
        std::string id;
        std::string name;
        std::vector<std::string> aliases;

    };

}

namespace nlohmann {
    template<>
    struct adl_serializer<firefly::ProcessingType> {
        static void to_json(json &j, const firefly::ProcessingType &pt) {
            j = json{{"id",   pt.getId()},
                     {"name", pt.getName()}};
        }
    };
}

#endif //FIREFLY_PROCESSINGTYPE_HPP
