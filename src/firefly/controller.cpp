// Copyright 2017 <Célian Garcia>

#include "./firefly/controller.hpp"
#include "./firefly/operation.hpp"
#include <iostream>
#include <opencv2/core.hpp>
#include <string>
#include "libpq-fe.h"

namespace firefly {
namespace controller {

    // TODO(célian):  this functions is very large ! I need to:
    //  - encapsulate the connection/insert/select/disconnection into functions (firefly::model)
    //  - encapsulate the connection/insert/select/disconnection into functions (firefly::workers)
    int start_module(thread_pool *pool, const std::string &name) {

        // - Initiate database connection
        PGconn *conn = PQconnectdb("user=postgres password=postgres dbname=fcloudpopulation hostaddr=127.0.0.1 port=5432");
        if (PQstatus(conn) != CONNECTION_OK) {
            std::cout << "Connection failed : " << PQerrorMessage(conn) << std::endl;
            PQfinish(conn);
            return 0;
        }

        // - Insert cloud entry in the database
        PGresult *res = PQexec(conn, "INSERT INTO fcloud3d (state) VALUES ('CREATED')");
        if (PQresultStatus(res) != PGRES_COMMAND_OK) {
            std::cout << "Insertion failed :" << PQresultErrorMessage(res) << std::endl;
            PQclear(res);
            PQfinish(conn);
            return 0;
        }
        PQclear(res);

        // - get the id information of the cloud entry
        res = PQexec(conn, "SELECT max(id) FROM fcloud3d");
        if (PQresultStatus(res) != PGRES_TUPLES_OK) {
            std::cout << "Selection last failed :" << PQresultErrorMessage(res) << std::endl;
            PQclear(res);
            PQfinish(conn);
            return 0;
        }
        int cloud_id = PQgetvalue(res, 0, 0);
        PQclear(res);

        // Close database connection
        PQfinish(conn);

        SafeQueue<Operation>* operations = new SafeQueue<Operation>;

        // Initiate a first thread into the thread pool
        // This thread will write to the queue the cloud operations (add/delete)
        pool->enqueue([name, operations] {
            std::cout
                << "Thread starts for the module : " << name
                << std::endl;

            for (int i = 0; i < 10; ++i) {
                Sleep(1000);
                operations->enqueue(Operation(OperationType::ADD, cv::Vec3f(i, i, i)));
                std::cout << "Enqueue operation " << i << std::endl;
            }
            operations->enqueue(Operation(OperationType::END, cv::Vec3f(0, 0, 0)));

            std::cout
                << "Thread have finished the work for the module : " << name
                << std::endl;
        });

        // Initiate a second thread into the thread pool
        // This thread will listen the queue continuously to populate the
        // database cloud with listened points
        pool->enqueue([cloud_id, operations] {
            // TODO(Célian) : update the cloud state to PROCESSING
            std::cout
                << "Thread starts for the cloud id : " << cloud_id
                << std::endl;
            bool end_operation_found = false;
            while (!end_operation_found) {
                Operation op = operations->dequeue();
                end_operation_found = op.getType() == OperationType::END;
                std::cout << "Dequeue operation " << op.getX() << std::endl;
                // TODO(Célian): insert the operation into the database
            }
            // TODO(Célian) : update the cloud state to FINISHED
            std::cout
                << "Thread have finished the work for the cloud_id : " << cloud_id
                << std::endl;
        });

        return cloud_id;
    }

    void listen_module() {}
}  // end namespace controller
}  // end namespace firefly
