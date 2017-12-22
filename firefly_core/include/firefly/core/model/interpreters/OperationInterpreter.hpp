// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_CORE_INCLUDE_FIREFLY_CORE_MODEL_INTERPRETERS_OPERATIONINTERPRETER_HPP_
#define FIREFLY_CORE_INCLUDE_FIREFLY_CORE_MODEL_INTERPRETERS_OPERATIONINTERPRETER_HPP_

#include <libpq-fe.h>
#include <vector>
#include <map>
#include <string>
#include <firefly/core/data/Operation.hpp>
#include "PGResultInterpreter.hpp"

namespace firefly {

class OperationInterpreter : public PGResultInterpreter {
 public:
    explicit OperationInterpreter(PGresult *result);

    Operation getOperation(int row);

 private:
    const std::vector<const char *> PROPERTIES();

    static std::map<std::string, OperationType> OPERATION_TYPES;
};

}  // namespace firefly

#endif  // FIREFLY_CORE_INCLUDE_FIREFLY_CORE_MODEL_INTERPRETERS_OPERATIONINTERPRETER_HPP_
