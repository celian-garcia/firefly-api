// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_CORE_INCLUDE_FIREFLY_CORE_DATA_MODULE_HPP_
#define FIREFLY_CORE_INCLUDE_FIREFLY_CORE_DATA_MODULE_HPP_

#include <string>
#include <vector>
#include <json/json.hpp>
#include "ProcessingType.hpp"

namespace firefly {

class Module {
 public:
    Module() = default;

    Module(const std::string &name, const std::string &description);

    const int &getId() const;

    const std::string &getTitle() const;

    const std::string &getDescription() const;

    const std::string &getImagePath() const;

    const std::vector<ProcessingType> &getProcessingTypesList() const;

    const std::string &getVersion() const;

    const std::string &getName() const;

    void setId(const int &id);

    void setTitle(const std::string &title);

    void setDescription(const std::string &description);

    void setImagePath(const std::string &imagePath);

    void setVersion(const std::string &version);

    void setProcessingTypesList(const std::vector<ProcessingType> &processingTypesList);

    void setName(const std::string &name);

 private:
    int id;
    std::string title;
    std::string name;
    std::string description;
    std::string imagePath;
    std::string version;
    std::vector<ProcessingType> processingTypesList;
};

}  // namespace firefly

namespace nlohmann {
template<>
struct __attribute__((unused)) adl_serializer<firefly::Module> {
    static void __attribute__((unused)) to_json(json &j, const firefly::Module &m) {
        j = json{{"id",               m.getId()},
                 {"title",            m.getTitle()},
                 {"description",      m.getDescription()},
                 {"image_path",       m.getImagePath()},
                 {"processing_types", m.getProcessingTypesList()},
                 {"version",          m.getVersion()}};
    }
};
}  // namespace nlohmann

#endif  // FIREFLY_CORE_INCLUDE_FIREFLY_CORE_DATA_MODULE_HPP_
