// Copyright 2017 <Célian Garcia>

#include <firefly/core/model/DatabaseManager.hpp>

namespace firefly {

DatabaseManager::DatabaseManager(const std::string &db_name) {
    std::string conn_str =
            "user=" + this->USER + " " +
            "password=" + this->PASSWORD + " " +
            "dbname=" + db_name + " " +
            "host=" + this->HOST + " " +
            "port=" + this->PORT + " ";

//    std::cout << "Connecting to database with the following connection string : " + conn_str << std::endl;

    this->m_connection = PQconnectdb(conn_str.c_str());

    if (PQstatus(this->m_connection) != CONNECTION_OK) {
        std::string errMessage = PQerrorMessage(this->m_connection);
        throw FireflyException(HtmlStatusCode::INTERNAL_SERVER_ERROR, errMessage);
    }

    PQinitTypes(this->m_connection);
}

DatabaseManager::~DatabaseManager() {
    PQfinish(this->m_connection);
}

void
DatabaseManager::execInsertQuery(const std::string &query) {
//    std::cout << "Insert/Update query execution: " << query << std::endl;
    PGresult *res = PQexec(this->m_connection, query.c_str());
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        std::string errMessage = PQresultErrorMessage(res);
        std::cerr << errMessage << "\n" << std::endl;
        PQclear(res);
        throw FireflyException(HtmlStatusCode::INTERNAL_SERVER_ERROR, errMessage);
    }
    PQclear(res);
}

void
DatabaseManager::execUpdateQuery(const std::string &query) {
    this->execInsertQuery(query);
}

PGresult *
DatabaseManager::execSelectQuery(const std::string &query) {
//    std::cout << "Select query execution: " << query << std::endl;
    PGresult *res = PQexec(this->m_connection, query.c_str());

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        std::string errMessage = PQresultErrorMessage(res);
        std::cerr << errMessage << "\n" << std::endl;
        PQclear(res);
        throw FireflyException(HtmlStatusCode::INTERNAL_SERVER_ERROR, errMessage);
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
    return "ST_Makepoint(" + format(obj[0]) + ", " + format(obj[1]) + ", " + format(obj[2]) + ")";
}

std::string
DatabaseManager::format(const std::vector<int> &objs) {
    int64 size = objs.size();
    std::string result = "\'{";
    for (int64 i = 0; i < size - 1; i++) {
        result += std::to_string(objs[i]) + ", ";
    }
    result += std::to_string(objs[size - 1]) + "}\'";
    return result;
}

std::string
DatabaseManager::format(const std::string &obj) {
    return "\'" + obj + "\'";
}

}  // namespace firefly
