// Copyright 2017 <Célian Garcia>

#include <libpqtypes.h>
#include <firefly/core/model/Point3DInterpreter.hpp>
#include "firefly/core/model/Point3DModel.hpp"

namespace firefly {

Point3DBean
Point3DModel::getPointByValueAndTaskId(cv::Vec3f value, int task_id) {
    double min_distance = Point3DModel::INTERSECT_MIN_DISTANCE;
    std::string select_query =
            "SELECT * FROM fpoint3d WHERE value <-> point " +
            this->m_dbmanager->format(value) + " < " +
            this->m_dbmanager->format(min_distance) +
            " AND task_id = " +
            this->m_dbmanager->format(task_id);

    PGresult *res = this->m_dbmanager->execSelectQuery(select_query.c_str());

    if (PQntuples(res) == 0) {
        throw ObjectNotFound();
    }

    // TODO(Célian) : get correctly the point from the database
    // int id_fnum = PQfnumber(res, "id");
    // int task_id_fnum = PQfnumber(res, "task_id");
    // int value_fnum = PQfnumber(res, "value");
    // int operations_fnum = PQfnumber(res, "operations");
    // int point_id = atoi(PQgetvalue(res, 0, id_fnum));
    // std::cout << PQntuples(res) << std::endl;
    // std::string value = PQgetvalue(res, 0, value_fnum);
    // // std::cout << value << std::endl;
    // std::string operations = PQgetvalue(res, 0, operations_fnum);
    // // std::cout << operations << std::endl;
    // m_dbmanager->clearResult(res);
    return Point3DBean(value, task_id, {0});
}

std::vector<Point3DBean>
Point3DModel::getPointListByTaskId(int task_id) {
    std::string select_query =
            "SELECT * FROM fpoint3d WHERE task_id = " +
            this->m_dbmanager->format(task_id) + ";";

    PGresult *res = this->m_dbmanager->execSelectQuery(select_query.c_str());


    // Initialize interpreter
    Point3DInterpreter interpreter(res);

    // Get the point list
    std::vector<Point3DBean> points_list;
    for (int row = 0; row < interpreter.get_row_number(); row++) {
        // Get the point from row
        points_list.push_back(interpreter.getPoint3D(row));
    }
    return points_list;
}

void
Point3DModel::insertPoint(Point3DBean point) {
    std::string insert_query =
            "INSERT INTO fpoint3d (task_id, value, operations) VALUES (" +
            this->m_dbmanager->format(point.getTaskId()) + ", " +
            this->m_dbmanager->format(point.getValue()) + ", " +
            this->m_dbmanager->format(point.getOperationsIds()) + ")";

    this->m_dbmanager->execInsertQuery(insert_query.c_str());
}

void Point3DModel::updatePoint(Point3DBean point) {
    std::string update_query =
            "UPDATE fpoint3d SET task_id = " +
            this->m_dbmanager->format(point.getTaskId()) + ", value = " +
            this->m_dbmanager->format(point.getValue()) + ", operations = " +
            this->m_dbmanager->format(point.getOperationsIds()) + " WHERE id = " +
            this->m_dbmanager->format(point.getId());

    this->m_dbmanager->execUpdateQuery(update_query.c_str());
}

int Point3DModel::insertOperation(Operation operation, int task_id) {
    if (operation.getType() == OperationType::END) {
        throw FireflyException(HtmlStatusCode::INTERNAL_SERVER_ERROR, "Cannot insert an END operation");
    }
    cv::Vec3f operation_value = operation.getValue();
    std::string operation_str = operation.getType() == OperationType::ADD ? "add" : "del";

    std::string method = "save_" + operation_str + "_operation";
    std::string select_query =
            "SELECT * FROM " + method + " (" +
            this->m_dbmanager->format(operation.getValue()) + ", " +
            this->m_dbmanager->format(task_id) + ")";

    PGresult *res = this->m_dbmanager->execSelectQuery(select_query);

    PGResultInterpreter interpreter(res);
    interpreter.registerProperty(method.c_str());
    return interpreter.get<int>(method.c_str(), 0);
}
}