// Copyright 2017 <Célian Garcia>

#include "firefly/core/data/Module.hpp"

namespace firefly {
    Module::Module(const std::string &title, const std::string &description, const std::string &imagePath) :
            title(title), description(description), imagePath(imagePath) {}

    const std::string &Module::getTitle() const {
        return title;
    }

    const std::string &Module::getDescription() const {
        return description;
    }

    const std::string &Module::getImagePath() const {
        return imagePath;
    }

    const std::vector<ProcessingType> &Module::getProcessingTypesList() const {
        return processingTypesList;
    }

    const std::string &Module::getId() const {
        return id;
    }

    const std::string &Module::getVersion() const {
        return version;
    }

}