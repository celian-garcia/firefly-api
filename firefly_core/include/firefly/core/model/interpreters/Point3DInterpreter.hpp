// Copyright 2017 <Célian Garcia>

#pragma once

#include <libpq-fe.h>
#include <vector>
#include <firefly/core/model/beans/Point3DBean.hpp>
#include <firefly/core/model/interpreters/PGResultInterpreter.hpp>

namespace firefly {
class Point3DInterpreter : public PGResultInterpreter {
 public:
    explicit Point3DInterpreter(PGresult *result);

    Point3DBean getPoint3D(int row);

 private:
    const std::vector<const char *> PROPERTIES();
};
}  // namespace firefly

