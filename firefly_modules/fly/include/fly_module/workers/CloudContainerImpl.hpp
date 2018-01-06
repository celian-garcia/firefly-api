// Copyright 2018 <Célian Garcia>

#ifndef FIREFLY_MODULES_FLY_INCLUDE_FLY_MODULE_WORKERS_CLOUDCONTAINERIMPL_HPP_
#define FIREFLY_MODULES_FLY_INCLUDE_FLY_MODULE_WORKERS_CLOUDCONTAINERIMPL_HPP_

#include <thread>
#include <fly/CloudContainer.hpp>
#include <firefly/core/model/OperationModel.hpp>
#include <firefly/core/utils/ConcurrentOperationQueue.hpp>

namespace firefly {
namespace fly_module {

class CloudContainerImpl : public fly::CloudContainer {
 public:
    using CloudContainer::add_point;

    explicit CloudContainerImpl(ConcurrentOperationQueue *m_queue) : m_queue(m_queue) {}

    virtual void add_point(cv::Vec3f v) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        m_queue->enqueue({OperationType::ADD, {"fpoint3d", v}});

        // TODO(célian): since this code is no longer necessary we have just to transform the CloudContainer into
        // an interface
//        CloudContainer::add_point(v);
    }

 private:
    ConcurrentOperationQueue * m_queue;
};

}  // namespace fly_module
}  // namespace firefly

#endif  // FIREFLY_MODULES_FLY_INCLUDE_FLY_MODULE_WORKERS_CLOUDCONTAINERIMPL_HPP_
