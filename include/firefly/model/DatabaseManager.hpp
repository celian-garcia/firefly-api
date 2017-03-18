// Copyright 2017 <Célian Garcia>

#ifndef INCLUDE_FIREFLY_MODEL_DATABASEMANAGER_HPP_
#define INCLUDE_FIREFLY_MODEL_DATABASEMANAGER_HPP_
#include <string>
#include <vector>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "./libpq-fe.h"

namespace firefly {
namespace model {

class DatabaseException : public std::exception {
 public:
    explicit DatabaseException(std::string message);

    virtual const char* what() const throw();
 private:
    std::string m_message;
};

class DatabaseManager {
 public:
    explicit DatabaseManager(const std::string& db_name);
    ~DatabaseManager();
    void execInsertQuery(const std::string& query);
    void execUpdateQuery(const std::string& query);
    PGresult* execSelectQuery(const std::string& query);
    void clearResult(PGresult* result);
    std::string format(const int&);
    std::string format(const cv::Vec3f&);
    std::string format(const std::vector<int>&);
    std::string format(const std::string&);
 protected:
    PGconn* m_connection;
    // TODO(Célian): put it in configuration file
    const std::string USER = "postgres";
    const std::string PASSWORD = "postgres";
    const std::string HOST = "127.0.0.1";
    const std::string PORT = "5432";
};

class BaseModel {
 public:
    explicit BaseModel(DatabaseManager* manager): m_dbmanager(manager) {}
 protected:
    DatabaseManager* m_dbmanager;
};

}  // namespace model
}  // namespace firefly
#endif  // INCLUDE_FIREFLY_MODEL_DATABASEMANAGER_HPP_
