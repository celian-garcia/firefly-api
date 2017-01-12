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
        "INSERT INTO fcloud3d (state) VALUES ('" + cloud.getState() + "')";
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
    // TODO(Célian)
}

// class FPoint3DModel : public BaseModel {
//  public:
//     std::vector<FPoint3D> getPointsByCloudId(int cloud_id);
//     FPoint3D getPointByXYZ(double x, double y, double z);
//     void insertPoint(FPoint3D point);
//     void updatePoint(FPoint3D point);
// }

}  // namespace model
}  // namespace firefly
