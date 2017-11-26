//
// Created by celian on 26/11/17.
//

#ifndef FIREFLY_OPERATIONINTERPRETER_H
#define FIREFLY_OPERATIONINTERPRETER_H


#include <vector>
#include <map>
#include <string>
#include <libpq-fe.h>
#include <firefly/core/utils/Operation.hpp>
#include "PGResultInterpreter.hpp"

namespace firefly {

class OperationInterpreter {
 public:
    explicit OperationInterpreter(PGresult *result);

    virtual ~OperationInterpreter();

    Operation getOperation(int row);

    int get_row_number();

 private:
    static const std::vector<const char *> PROPERTIES();

    static std::map<std::string, OperationType> OPERATION_TYPES;

    PGResultInterpreter *interpreter;
};

}


#endif //FIREFLY_OPERATIONINTERPRETER_H
