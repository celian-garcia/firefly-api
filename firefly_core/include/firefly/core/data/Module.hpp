// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_MODULE_HPP
#define FIREFLY_MODULE_HPP

#include <string>
#include "Processing.hpp"

namespace firefly {

    class Module {
    public:
        Module(const std::string &title, const std::string &description, const std::string &imagePath);

        const std::string &getId() const;

        const std::string &getTitle() const;

        const std::string &getDescription() const;

        const std::string &getImagePath() const;

        const std::vector<ProcessingType> &getProcessingTypesList() const;

        const std::string &getVersion() const;

    private:
        std::string id;
        std::string title;
        std::string description;
        std::string imagePath;
        std::string version;
        std::vector<ProcessingType> processingTypesList;
    };
}

namespace nlohmann {
    template<>
    struct adl_serializer<firefly::Module> {
        static void to_json(json &j, const firefly::Module &m) {
            j = json{
                    {"id",    m.getId()},
                    {"title", m.getTitle()},
                    {"description", m.getDescription()},
                    {"image_path", m.getImagePath()},
                    {"processing_types", m.getProcessingTypesList()},
                    {"version", m.getVersion()}
            };
        }
    };
}

#endif //FIREFLY_MODULE_HPP
