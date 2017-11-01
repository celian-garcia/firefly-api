// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_FLYCLOUDPOPULATION_HPP
#define FIREFLY_FLYCLOUDPOPULATION_HPP

#include <vector>
#include <chrono>
#include <thread>
#include <string>
#include <firefly/core/utils/Operation.hpp>
#include <firefly/core/utils/FireflyException.hpp>
#include <firefly/core/utils/ProcessAction.hpp>
#include <firefly/core/model/DatabaseManager.hpp>
#include <firefly/core/utils/ThreadPool.hpp>
#include <firefly/core/model/beans/Point3DBean.hpp>
#include <firefly/core/model/Point3DModel.hpp>
#include <firefly/core/model/TaskModel.hpp>

namespace firefly {
namespace fly_module {
class FlyCloudPopulation {
public:

    static int start(int task_id, ThreadPool *pool);

    static void stop();

    static std::vector<Operation> collect(int task_id, int client_last_op);

private:
    static const std::string DATABASE_NAME;

    static void run_compute_thread(ConcurrentOperationQueue *queue);

    static void run_populate_thread(int cloud_id, ConcurrentOperationQueue *queue);

    static std::vector<Operation>
    computeOperationsFromPoints(const std::vector<Point3DBean> &points, int last_operation);

    static Operation computeOperationFromPoint(const Point3DBean &point, int last_operation);
};
}
}

#endif //FIREFLY_FLYCLOUDPOPULATION_HPP
