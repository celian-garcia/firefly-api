//
// Created by celian on 26/11/17.
//

#include <firefly/core/model/interpreters/OperationInterpreter.hpp>
#include "firefly/core/model/OperationModel.hpp"

namespace firefly {

std::vector<Operation> OperationModel::getOperationsSince(int task_id, int last_operation) {
    std::string select_query =
            "SELECT * FROM collect_operations(" +
            this->m_dbmanager->format(task_id) + ", " +
            this->m_dbmanager->format(last_operation) + ");";

    PGresult *res = this->m_dbmanager->execSelectQuery(select_query.c_str());

    // Initialize interpreter
    OperationInterpreter interpreter(res);

    // Get the operation list
    std::vector<Operation> operations_list;
    for (int row = 0; row < interpreter.get_row_number(); row++) {
        // Get the operation from row
        operations_list.push_back(interpreter.getOperation(row));
    }
    return operations_list;
}

}