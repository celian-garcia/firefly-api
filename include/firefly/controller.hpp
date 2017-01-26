// Copyright 2017 <Célian Garcia>

#ifndef INCLUDE_FIREFLY_CONTROLLER_HPP_
#define INCLUDE_FIREFLY_CONTROLLER_HPP_
#include <string>
#include <iostream>
#include <opencv2/core.hpp>
#include "firefly/thread_pool.hpp"
#include "firefly/safe_queue.hpp"
#include "firefly/operation.hpp"
#include "firefly/model/DatabaseManager.hpp"
#include "firefly/model/fcloudpopulation_beans.hpp"
#include "firefly/model/fcloudpopulation_model.hpp"
#include "./libpq-fe.h"

namespace firefly {
namespace controller {

    int start_module(thread_pool*, const std::string& name);

    std::vector<Operation> harvest_module(const std::string& module_name, const int& cloud_id, const int& client_last_op);
}  // end namespace controller
}  // end namespace firefly
#endif  // INCLUDE_FIREFLY_CONTROLLER_HPP_
