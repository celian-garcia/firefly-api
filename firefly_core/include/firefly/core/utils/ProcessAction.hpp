// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_MODULEACTION_HPP
#define FIREFLY_MODULEACTION_HPP
#include <string>
#include <algorithm>
#include <vector>
#include "FireflyException.hpp"
#include "HtmlStatusCode.hpp"
#include <boost/algorithm/string.hpp>

namespace firefly {
    enum ProcessActionType {
        START = 0,
        STOP = 1,
        COLLECT = 2
    };

    class ProcessAction {
    public:
        ProcessAction(const std::string& raw_input) {
            this->m_value = raw_input;
            boost::to_lower(this->m_value);
            auto it = std::find(TYPES.begin(), TYPES.end(), this->m_value);
            if (it == TYPES.end()) {
                throw  FireflyException(HtmlStatusCode::BAD_REQUEST, this->m_value + " action does not exist.");
            } else {
                this->m_type = ProcessActionType(std::distance(TYPES.begin(), it));
            }
        };

        std::string getValue() {
            return this->m_value;
        };

        ProcessActionType getActionType() {
            return this->m_type;
        };

    private:
        const std::vector<std::string> TYPES = {
                "start",
                "stop",
                "collect"
        };
        std::string m_value;
        ProcessActionType m_type;
    };

}
#endif //FIREFLY_MODULEACTION_HPP
