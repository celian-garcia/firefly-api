// Copyright 2017 <Célian Garcia>

#include "firefly/model/fcloudpopulation_model.hpp"
#include <iostream>

namespace firefly {
namespace model {

FCloud3D
FCloud3DModel::getCloudById(int id) {
    std::string query =
        "SELECT * FROM fcloud3d WHERE id = " + std::to_string(id);
    std::cout << query << std::endl;
    std::cout << query.c_str() << std::endl;
    PGresult* res = this->m_dbmanager->execSelectQuery(query.c_str());
    std::string state = PQgetvalue(res, 0, 1);
    return FCloud3D(id, state);
}

int
FCloud3DModel::insertCloud(const FCloud3D& cloud) {
    std::string insert_query =
        "INSERT INTO fcloud3d (state) VALUES (" +
        this->m_dbmanager->format(cloud.getState()) + ")";
    std::string select_query =
        "SELECT max(id) FROM fcloud3d";

    // TODO(Célian) : Danger if an insert command is run asynchronously
    // between the two following lines....
    this->m_dbmanager->execInsertQuery(insert_query.c_str());
    PGresult* res = this->m_dbmanager->execSelectQuery(select_query.c_str());

    int cloud_id = atoi(PQgetvalue(res, 0, 0));
    m_dbmanager->clearResult(res);
    return cloud_id;
}

void
FCloud3DModel::updateCloud(const FCloud3D& cloud) {
    std::string update_query =
        "UPDATE fcloud3d SET state = " +
        this->m_dbmanager->format(cloud.getState()) +
        " where id = " +
        this->m_dbmanager->format(cloud.getId());

    this->m_dbmanager->execUpdateQuery(update_query.c_str());
}

FPoint3D
FPoint3DModel::getPointByValueAndCloudId(cv::Vec3f value, int cloud_id) {
    std::string select_query =
        "SELECT * FROM fpoint3d WHERE value <-> point " +
        this->m_dbmanager->format(value)+ " < " +
        this->m_dbmanager->format(this->INTERSECT_MIN_DISTANCE) +
        " AND cloud_id = " +
        this->m_dbmanager->format(cloud_id);

    PGresult* res = this->m_dbmanager->execSelectQuery(select_query.c_str());

    if (PQntuples(res) == 0) {
        throw ObjectNotFound();
    }

    // TODO(Célian) : get correctly the point from the database
    // int id_fnum = PQfnumber(res, "id");
    // int cloud_id_fnum = PQfnumber(res, "cloud_id");
    // int value_fnum = PQfnumber(res, "value");
    // int operations_fnum = PQfnumber(res, "operations");
    // int point_id = atoi(PQgetvalue(res, 0, id_fnum));
    // std::cout << PQntuples(res) << std::endl;
    // std::string value = PQgetvalue(res, 0, value_fnum);
    // // std::cout << value << std::endl;
    // std::string operations = PQgetvalue(res, 0, operations_fnum);
    // // std::cout << operations << std::endl;
    // m_dbmanager->clearResult(res);
    return FPoint3D(value, cloud_id, {0});
}

std::vector<FPoint3D>
FPoint3DModel::getPointListByCloudId(int cloud_id) {
    std::string select_query =
        "SELECT * FROM fpoint3d WHERE cloud_id = " +
        this->m_dbmanager->format(cloud_id);

    PGresult* res = this->m_dbmanager->execSelectQuery(select_query.c_str());

    int rows_number = PQntuples(res);
    if (rows_number == 0) {
        throw ObjectNotFound();
    }

    int id_fnum = PQfnumber(res, "id");
    int cloud_id_fnum = PQfnumber(res, "cloud_id");
    int value_fnum = PQfnumber(res, "value");
    int operations_fnum = PQfnumber(res, "operations");

    for (int row; row < rows_number; row++) {
        char* id = PQgetvalue(res, row, id_fnum);
        char* cloud_id = PQgetvalue(res, row, cloud_id_fnum);
        char* value = PQgetvalue(res, row, value_fnum);
        char* operations = PQgetvalue(res, row, operations_fnum);
        std::cout << std::string(id) << std::endl;
        std::cout << std::string(cloud_id) << std::endl;
        std::cout << std::string(value) << std::endl;
        std::cout << std::string(operations) << std::endl;
    }

    return std::vector<FPoint3D>();

}

void
FPoint3DModel::insertPoint(FPoint3D point) {
    std::string insert_query =
        "INSERT INTO fpoint3d (cloud_id, value, operations) VALUES (" +
        this->m_dbmanager->format(point.getCloudId()) + ", " +
        this->m_dbmanager->format(point.getValue()) + ", " +
        this->m_dbmanager->format(point.getOperations()) + ")";

    this->m_dbmanager->execInsertQuery(insert_query.c_str());
}

void
FPoint3DModel::updatePointOperations(FPoint3D point) {
    std::cout << "Point update" << std::endl;
}

}  // namespace model
}  // namespace firefly
