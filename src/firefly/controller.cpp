// Copyright 2017 <Célian Garcia>

#include "./firefly/controller.hpp"
#include "./firefly/operation.hpp"
#include <windows.h>
#include <iostream>
#include <opencv2/core.hpp>
namespace firefly {
namespace controller {

    std::string start_module(thread_pool *pool, const std::string &name) {
        // TODO(Célian Garcia)
        // - Initiate database connection
        // - Insert cloud entry in the database
        // - get the id information of the cloud entry
        std::string cloud_id = "future database cloud id";
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
            std::cout
                << "Thread starts for the cloud id : " << cloud_id
                << std::endl;
            bool end_operation_found = false;
            while (!end_operation_found) {
                Operation op = operations->dequeue();
                end_operation_found = op.getType() == OperationType::END;
                std::cout << "Dequeue operation " << op.getX() << std::endl;
            }
            std::cout
                << "Thread have finished the work for the cloud_id : " << cloud_id
                << std::endl;
        });

        return "A module ID";
    }

    void listen_module() {}
}  // end namespace controller
}  // end namespace firefly
