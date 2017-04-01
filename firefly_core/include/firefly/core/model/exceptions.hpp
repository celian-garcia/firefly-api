// Copyright 2017 <Célian Garcia>

#ifndef INCLUDE_FIREFLY_MODEL_EXCEPTIONS_HPP_
#define INCLUDE_FIREFLY_MODEL_EXCEPTIONS_HPP_

#include "firefly/core/utils/FireflyException.hpp"

namespace firefly {

    class ObjectNotFound : public FireflyException {
    public:
        ObjectNotFound() {
            FireflyException(HtmlStatusCode::INTERNAL_SERVER_ERROR, "Object not found.");
        }
    };

}  // namespace firefly
#endif  // INCLUDE_FIREFLY_MODEL_EXCEPTIONS_HPP_
