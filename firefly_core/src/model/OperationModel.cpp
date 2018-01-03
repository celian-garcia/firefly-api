// Copyright 2017 <Célian Garcia>

#include <firefly/core/model/OperationModel.hpp>

int firefly::OperationModel::insertOperation(Operation operation, int task_id) {
    cv::Vec3f operation_value = operation.getElement().getValue();
    std::string operation_str = operation.getType() == ADD ? "add" : "del";

    std::string method = "save_" + operation_str + "_operation";
    std::string select_query =
            "SELECT * FROM " + method + " (" +
            this->m_dbmanager->format(operation_value) + ", " +
            this->m_dbmanager->format(task_id) + ")";

    PGresult *res = this->m_dbmanager->execSelectQuery(select_query);

    PGResultInterpreter interpreter(res);
    interpreter.registerProperty(method.c_str());
    return interpreter.get<int>(method.c_str(), 0);
}

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

}  // namespace firefly
