// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_CORE_INCLUDE_FIREFLY_CORE_DATA_PROCESSINGTYPE_HPP_
#define FIREFLY_CORE_INCLUDE_FIREFLY_CORE_DATA_PROCESSINGTYPE_HPP_

#include <string>
#include <vector>

#include <json/json.hpp>

namespace firefly {

class ProcessingType {
 public:
    ProcessingType() = default;

    ProcessingType(const std::string &name, const std::vector<std::string> &aliases);

    const std::string &getName() const;

    const std::vector<std::string> &getAliases() const;

    const int &getId() const;

    void setId(const int &id);

 private:
    int id;
    std::string name;
    std::vector<std::string> aliases;
};

}  // namespace firefly

namespace nlohmann {
template<>
struct __attribute__((unused)) adl_serializer<firefly::ProcessingType> {
    static void __attribute__((unused)) to_json(json &j, const firefly::ProcessingType &pt) {
        j = json{{"id",   pt.getId()},
                 {"name", pt.getName()}};
    }
};
}  // namespace nlohmann

#endif  // FIREFLY_CORE_INCLUDE_FIREFLY_CORE_DATA_PROCESSINGTYPE_HPP_
