// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_MODULE_HPP
#define FIREFLY_MODULE_HPP

#include <string>
#include "ProcessingType.hpp"

namespace firefly {

    class Module {
    public:

        Module() = default;

        Module(const std::string &name, const std::string &description);

        const std::string &getId() const;

        const std::string &getTitle() const;

        const std::string &getDescription() const;

        const std::string &getImagePath() const;

        const std::vector<ProcessingType> &getProcessingTypesList() const;

        const std::string &getVersion() const;

        const std::string &getName() const;

        void setId(const std::string &id);

        void setTitle(const std::string &title);

        void setDescription(const std::string &description);

        void setImagePath(const std::string &imagePath);

        void setVersion(const std::string &version);

        void setProcessingTypesList(const std::vector<ProcessingType> &processingTypesList);

        void setName(const std::string &name);

//        static const std::vector<Module> STORES = {
//                Module("Reconstruction3D", {}),
//                Module("Population3D", {})
//        };

    private:
        std::string id;
        std::string title;
        std::string name;
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
                    {"id",               m.getId()},
                    {"title",            m.getTitle()},
                    {"description",      m.getDescription()},
                    {"image_path",       m.getImagePath()},
                    {"processing_types", m.getProcessingTypesList()},
                    {"version",          m.getVersion()}
            };
        }
    };
}

#endif //FIREFLY_MODULE_HPP
