// Copyright 2017 <Célian Garcia>

#ifndef INCLUDE_FIREFLY_CONTROLLER_HPP_
#define INCLUDE_FIREFLY_CONTROLLER_HPP_
#include <string>
#include "./firefly/thread_pool.hpp"
#include "./firefly/safe_queue.hpp"
namespace firefly {
namespace controller {

    std::string start_module(thread_pool*, const std::string&);

    void listen_module();
}  // end namespace controller
}  // end namespace firefly
#endif  // INCLUDE_FIREFLY_CONTROLLER_HPP_
