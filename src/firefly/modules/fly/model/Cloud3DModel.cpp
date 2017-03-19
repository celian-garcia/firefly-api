// Copyright 2017 <Célian Garcia>

#include "firefly/modules/fly/model/Cloud3DModel.hpp"

namespace firefly {
    namespace module_fly {

        Cloud3DBean
        Cloud3DModel::getCloudById(int id) {
            std::string query =
                    "SELECT * FROM fcloud3d WHERE id = " + std::to_string(id);
            std::cout << query << std::endl;
            std::cout << query.c_str() << std::endl;
            PGresult *res = this->m_dbmanager->execSelectQuery(query.c_str());
            std::string state = PQgetvalue(res, 0, 1);
            return Cloud3DBean(id, state);
        }

        int
        Cloud3DModel::insertCloud(const Cloud3DBean &cloud) {
            std::string insert_query =
                    "INSERT INTO fcloud3d (state) VALUES (" +
                    this->m_dbmanager->format(cloud.getState()) + ")";
            std::string select_query =
                    "SELECT max(id) FROM fcloud3d";

            // TODO(Célian) : Danger if an insert command is run asynchronously
            // between the two following lines....
            this->m_dbmanager->execInsertQuery(insert_query.c_str());
            PGresult *res = this->m_dbmanager->execSelectQuery(select_query.c_str());

            int cloud_id = atoi(PQgetvalue(res, 0, 0));
            m_dbmanager->clearResult(res);
            return cloud_id;
        }

        void
        Cloud3DModel::updateCloud(const Cloud3DBean &cloud) {
            std::string update_query =
                    "UPDATE fcloud3d SET state = " +
                    this->m_dbmanager->format(cloud.getState()) +
                    " where id = " +
                    this->m_dbmanager->format(cloud.getId());

            this->m_dbmanager->execUpdateQuery(update_query.c_str());
        }
    }
}