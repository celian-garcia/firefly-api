// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_PROCESSING_HPP
#define FIREFLY_PROCESSING_HPP

#include <string>
#include "ProcessingType.hpp"

namespace firefly {

    class Processing {
    public:
        Processing(const std::string &title, const std::string &description, const ProcessingType &type);

        const std::string &getIdentifier() const;

        const std::string &getName() const;

        const std::string &getTitle() const;

        const std::string &getDescription() const;

        const ProcessingType &getType() const;

    private:
        std::string identifier;
        std::string name;
        std::string title;
        std::string description;
        ProcessingType type;
    };
}
#endif //FIREFLY_PROCESSING_HPP
