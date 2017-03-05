// Copyright 2017 <Célian Garcia>

#ifndef INCLUDE_FIREFLY_MODEL_EXCEPTIONS_HPP_
#define INCLUDE_FIREFLY_MODEL_EXCEPTIONS_HPP_
#include "firefly/utils/ff_exception.hpp"
namespace firefly {
namespace model {

using firefly::utils::ff_exception;
class ObjectNotFound : public ff_exception {};

}  // namespace model
}  // namespace firefly
#endif  // INCLUDE_FIREFLY_MODEL_EXCEPTIONS_HPP_
