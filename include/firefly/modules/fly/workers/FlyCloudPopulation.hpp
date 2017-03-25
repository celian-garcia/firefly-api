// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_FLYCLOUDPOPULATION_HPP
#define FIREFLY_FLYCLOUDPOPULATION_HPP

#include <vector>
#include <chrono>
#include <thread>
#include <firefly/Operation.hpp>
#include <firefly/utils/FireflyException.hpp>
#include <firefly/utils/ProcessAction.hpp>
#include <firefly/modules/common/model/DatabaseManager.hpp>
#include <firefly/modules/fly/model/Cloud3DModel.hpp>
#include <firefly/modules/fly/model/beans/Point3DBean.hpp>
#include <firefly/modules/fly/model/Point3DModel.hpp>
#include <firefly/utils/ThreadPool.hpp>

namespace firefly {
    namespace module_fly {
        class FlyCloudPopulation {
        public:

            static int start(ThreadPool *pool);

            static void stop();

            static std::vector<Operation> collect(int cloud_id, int client_last_op);

        private:
            static const std::vector<ProcessActionType> VALID_ACTION_TYPES;
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
