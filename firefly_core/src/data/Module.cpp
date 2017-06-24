// Copyright 2017 <Célian Garcia>

#include "firefly/core/data/Module.hpp"

namespace firefly {
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

    void Module::setId(const std::string &id) {
        Module::id = id;
    }

    void Module::setTitle(const std::string &title) {
        Module::title = title;
    }

    void Module::setDescription(const std::string &description) {
        Module::description = description;
    }

    void Module::setImagePath(const std::string &imagePath) {
        Module::imagePath = imagePath;
    }

    void Module::setVersion(const std::string &version) {
        Module::version = version;
    }

    void Module::setProcessingTypesList(const std::vector<ProcessingType> &processingTypesList) {
        Module::processingTypesList = processingTypesList;
    }

    const std::string &Module::getName() const {
        return name;
    }

    void Module::setName(const std::string &name) {
        Module::name = name;
    }

    Module::Module(const std::string &name, const std::string &description) : name(name), description(description) {}

}