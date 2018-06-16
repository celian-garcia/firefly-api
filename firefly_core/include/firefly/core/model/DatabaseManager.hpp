// Copyright 2017 <Célian Garcia>

#pragma once

#include <libpq-fe.h>
#include <libpqtypes.h>
#include <string>
#include <vector>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "firefly/core/utils/HtmlStatusCode.hpp"
#include "firefly/core/exception/FireflyException.hpp"

namespace firefly {

class DatabaseManager {
 public:
    explicit DatabaseManager(const std::string &db_name);

    ~DatabaseManager();

    void execInsertQuery(const std::string &query);

    void execUpdateQuery(const std::string &query);

    PGresult *execSelectQuery(const std::string &query);

    void clearResult(PGresult *result);

    std::string format(const int &);

    std::string format(const double &);

    std::string format(const cv::Vec3f &);

    std::string format(const std::vector<int> &);

    std::string format(const std::string &);

 protected:
    PGconn *m_connection;
    // TODO(Célian): put it in configuration file
    const std::string USER = "postgres";
    const std::string PASSWORD = "postgres";
    const std::string HOST = "database";
    const std::string PORT = "5432";
};

class BaseModel {
 public:
    explicit BaseModel(DatabaseManager *manager) : m_dbmanager(manager) {}

 protected:
    DatabaseManager *m_dbmanager;
};

}  // namespace firefly
