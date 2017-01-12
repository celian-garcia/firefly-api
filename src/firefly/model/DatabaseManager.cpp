// Copyright 2017 <Célian Garcia>
#include "firefly/model/DatabaseManager.hpp"

namespace firefly {
namespace model {

DatabaseException::DatabaseException(std::string message)
    : m_message(message) {}

const char*
DatabaseException::what() const throw() {
    return m_message.c_str();
}

DatabaseManager::DatabaseManager(const std::string& db_name) {
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
DatabaseManager::execInsertQuery(const std::string& query) {
    PGresult *res = PQexec(this->m_connection, query.c_str());
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        std::string errMessage = PQresultErrorMessage(res);
        PQclear(res);
        PQfinish(this->m_connection);
        throw DatabaseException(errMessage);
    }
    PQclear(res);
}

PGresult*
DatabaseManager::execSelectQuery(const std::string& query) {
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
DatabaseManager::clearResult(PGresult* result) {
    PQclear(result);
}

}  // namespace model
}  // namespace firefly
