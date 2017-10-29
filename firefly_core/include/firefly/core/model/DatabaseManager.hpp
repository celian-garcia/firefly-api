// Copyright 2017 <Célian Garcia>

#ifndef INCLUDE_FIREFLY_MODEL_DATABASEMANAGER_HPP_
#define INCLUDE_FIREFLY_MODEL_DATABASEMANAGER_HPP_

#include <string>
#include <vector>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <libpq-fe.h>
#include "firefly/core/utils/HtmlStatusCode.hpp"
#include "firefly/core/utils/FireflyException.hpp"

namespace firefly {

    class DatabaseException : public std::exception {
    public:
        explicit DatabaseException(std::string message);

        virtual const char *what() const throw();

    private:
        std::string m_message;
    };

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
        const std::string USER = "firefly_foreman";
        const std::string PASSWORD = "rootbug";
        const std::string HOST = "localhost";
        const std::string PORT = "5432";
    };

    class BaseModel {
    public:
        explicit BaseModel(DatabaseManager *manager) : m_dbmanager(manager) {}

    protected:
        DatabaseManager *m_dbmanager;
    };

}  // namespace firefly
#endif  // INCLUDE_FIREFLY_MODEL_DATABASEMANAGER_HPP_
