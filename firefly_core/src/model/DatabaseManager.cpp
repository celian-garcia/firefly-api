// Copyright 2017 <Célian Garcia>
#include "../../include/firefly/core/utils/HtmlStatusCode.hpp"
#include "../../include/firefly/core/utils/FireflyException.hpp"
#include "firefly/modules/common/model/DatabaseManager.hpp"

namespace firefly {

    DatabaseException::DatabaseException(std::string message)
            : m_message(message) {}

    const char *
    DatabaseException::what() const throw() {
        return m_message.c_str();
    }

    DatabaseManager::DatabaseManager(const std::string &db_name) {
        std::string conn_str =
                "user=" + this->USER + " " +
                "password=" + this->PASSWORD + " " +
                "dbname=" + db_name + " " +
                "hostaddr=" + this->HOST + " " +
                "port=" + this->PORT + " ";

        this->m_connection = PQconnectdb(conn_str.c_str());

        if (PQstatus(this->m_connection) != CONNECTION_OK) {
            std::string errMessage = PQerrorMessage(this->m_connection);
            PQfinish(this->m_connection);
            throw DatabaseException(errMessage);
        }
    }

    DatabaseManager::~DatabaseManager() {
        PQfinish(this->m_connection);
    }

    void
    DatabaseManager::execInsertQuery(const std::string &query) {
        PGresult *res = PQexec(this->m_connection, query.c_str());
        if (PQresultStatus(res) != PGRES_COMMAND_OK) {
            std::string errMessage = PQresultErrorMessage(res);
            PQclear(res);
            PQfinish(this->m_connection);
            throw DatabaseException(errMessage);
        }
        PQclear(res);
    }

    void
    DatabaseManager::execUpdateQuery(const std::string &query) {
        this->execInsertQuery(query);
    }

    PGresult *
    DatabaseManager::execSelectQuery(const std::string &query) {
        PGresult *res = PQexec(this->m_connection, query.c_str());

        if (PQresultStatus(res) != PGRES_TUPLES_OK) {
            std::string errMessage = PQresultErrorMessage(res);
            PQclear(res);
            PQfinish(this->m_connection);
            throw DatabaseException(errMessage);
        }
        return res;
    }

    void
    DatabaseManager::clearResult(PGresult *result) {
        PQclear(result);
    }

    std::string
    DatabaseManager::format(const int &obj) {
        return std::to_string(obj);
    }

    std::string
    DatabaseManager::format(const double &obj) {
        return std::to_string(obj);
    }

    std::string
    DatabaseManager::format(const cv::Vec3f &obj) {
        return std::string(
                "\'(" + std::to_string(obj[0]) + ", " + std::to_string(obj[1]) + ")\'");
    }

    std::string
    DatabaseManager::format(const std::vector<int> &objs) {
        unsigned long long int size = objs.size();
        std::string result = "\'{";
        for (unsigned long long int i = 0; i < size - 1; i++) {
            result += std::to_string(objs[i]) + ", ";
        }
        result += std::to_string(objs[size - 1]) + "}\'";
        return result;
    }

    std::string
    DatabaseManager::format(const std::string &obj) {
        return "\'" + obj + "\'";
    }

    int DatabaseManager::parse(std::string str) {
        try {
            return std::stoi(str);
        }
        catch (std::exception e) {
            throw FireflyException(HtmlStatusCode::INTERNAL_SERVER_ERROR, "Error parsing db query result.");
        }
    }

}  // namespace firefly
