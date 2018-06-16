// Copyright 2017 <Célian Garcia>

#pragma once

#include <vector>
#include <firefly/core/data/Task.hpp>
#include <firefly/core/config/DataCommonStore.hpp>
#include "PGResultInterpreter.hpp"

namespace firefly {
class TaskInterpreter : public PGResultInterpreter {
 public:
    explicit TaskInterpreter(PGresult* result, DataCommonStore* data_store);

    Task getTask(int row);

 private:
    const std::vector<const char *> PROPERTIES();

    DataCommonStore *m_data_store;
};
}  // namespace firefly
