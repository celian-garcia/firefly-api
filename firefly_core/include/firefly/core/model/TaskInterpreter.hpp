// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_TASKINTERPRETER_HPP
#define FIREFLY_TASKINTERPRETER_HPP

#include <firefly/core/data/Task.hpp>
#include <firefly/core/config/DataCommonStore.hpp>
#include "PGResultInterpreter.hpp"

namespace firefly {
    class TaskInterpreter {
    public:
        explicit TaskInterpreter(DataCommonStore * dataStore, PGresult *result);

        virtual ~TaskInterpreter();

        Task getTask(int row);

        int get_row_number();

    private:
        static const std::vector<const char *> PROPERTIES();

        PGResultInterpreter *interpreter;

        DataCommonStore* dataStore;
    };
}
#endif //FIREFLY_TASKINTERPRETER_HPP
