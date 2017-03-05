// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_MODULENAME_HPP
#define FIREFLY_MODULENAME_HPP

#include <string>
#include <algorithm>
#include <vector>
#include <firefly/utils/FireflyException.hpp>
#include <firefly/utils/HtmlStatusCode.hpp>
#include <boost/algorithm/string.hpp>

namespace firefly {

    enum ModuleType {
        RECONSTRUCTION3D = 0,
        CLOUDPOPULATION3D = 1,
        CVFILTERGAUSSIAN = 2,
        OPOPOLOP = 3
    };

    class ModuleName {
    public:
        ModuleName(const std::string &raw_input) {
            this->m_value = raw_input;
            boost::to_lower(this->m_value);
            auto it = std::find(TYPES.begin(), TYPES.end(), this->m_value);
            if (it == TYPES.end()) {
                throw FireflyException(HtmlStatusCode::BAD_REQUEST, this->m_value + " module does not exist.");
            } else {
                this->m_type = ModuleType(std::distance(TYPES.begin(), it));
            }
        };

        std::string getValue() {
            return this->m_value;
        };

        ModuleType getType() {
            return this->m_type;
        };

    private:
        const std::vector<std::string> TYPES = {
                "reconstruct3d",
                "cloudpopulation3d",
                "cvfiltergaussian",
                "opopolop"
        };
        std::string m_value;
        ModuleType m_type;
    };

}

#endif //FIREFLY_MODULENAME_HPP
