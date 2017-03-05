// Copyright 2017 <Célian Garcia>

#include "firefly/modules/opencv/api/OpencvHandler.hpp"

namespace module_cv {

    OpencvFilterHandler::OpencvFilterHandler(OpencvFilterType type) : m_type(type) {}

    void
    OpencvFilterHandler::handleRequest(shared_ptr <Response> response, shared_ptr <Request> request) {
        switch (this->m_type) {
            case OpencvFilterType::GAUSSIAN:
                throwNotYetImplementedError();
            case OpencvFilterType::MEDIAN:
                throwNotYetImplementedError();
            default:
                throwNotYetImplementedError();
        }
    }

    void
    OpencvFilterHandler::throwNotYetImplementedError() {
        throw FireflyException(
                HtmlStatusCode::NOT_IMPLEMENTED,
                "Type of opencv module handling is not yet implemented: module \""
                        << this->m_type << "\"");
    }
}  // end namespace module_cv
