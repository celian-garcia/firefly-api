// Copyright 2017 <Célian Garcia>

#pragma once

#include <string>
#include "firefly/api/IModuleHandler.hpp"

namespace module_cv {

    enum OpencvFilterType {
        GAUSSIAN, MEDIAN
    };

    class OpencvFilterHandler {
    public:
        explicit OpencvFilterHandler(OpencvFilterType type);

        void handleRequest(shared_ptr <Response> response, shared_ptr <Request> request);

    private:
        OpencvFilterType m_type;

        void throwNotYetImplementedError();
    };

}  // end namespace module_cv
