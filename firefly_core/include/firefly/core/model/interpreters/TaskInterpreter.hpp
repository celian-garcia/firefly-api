// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_CORE_INCLUDE_FIREFLY_CORE_MODEL_INTERPRETERS_TASKINTERPRETER_HPP_
#define FIREFLY_CORE_INCLUDE_FIREFLY_CORE_MODEL_INTERPRETERS_TASKINTERPRETER_HPP_

#include <vector>
#include <firefly/core/data/Task.hpp>
#include <firefly/core/config/DataCommonStore.hpp>
#include "PGResultInterpreter.hpp"

namespace firefly {
class TaskInterpreter : public PGResultInterpreter {
 public:
    using PGResultInterpreter::PGResultInterpreter;

    explicit TaskInterpreter(PGresult* result, DataCommonStore* data_store);

    Task getTask(int row);

 private:
    const std::vector<const char *> PROPERTIES();

    DataCommonStore *m_data_store;
};
}  // namespace firefly
#endif  // FIREFLY_CORE_INCLUDE_FIREFLY_CORE_MODEL_INTERPRETERS_TASKINTERPRETER_HPP_
