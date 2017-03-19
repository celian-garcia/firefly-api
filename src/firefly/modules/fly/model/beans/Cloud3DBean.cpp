// Copyright 2017 <Célian Garcia>
#include "firefly/modules/fly/model/beans/Cloud3DBean.hpp"

namespace firefly {
    namespace module_fly {
        Cloud3DBean::Cloud3DBean(int id, std::string state)
                : m_id(id), m_state(state) {}

        Cloud3DBean::Cloud3DBean(std::string state)
                : m_state(state) {}

        int const &
        Cloud3DBean::getId() const {
            return this->m_id;
        }

        std::string const &
        Cloud3DBean::getState() const {
            return this->m_state;
        }

        void
        Cloud3DBean::setState(const std::string &state) {
            this->m_state = state;
        }
    }
}