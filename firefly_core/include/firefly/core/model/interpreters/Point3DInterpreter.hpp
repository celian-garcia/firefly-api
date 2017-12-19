// Copyright 2017 <Célian Garcia>

#ifndef FIREFLY_CORE_INCLUDE_FIREFLY_CORE_MODEL_INTERPRETERS_POINT3DINTERPRETER_HPP_
#define FIREFLY_CORE_INCLUDE_FIREFLY_CORE_MODEL_INTERPRETERS_POINT3DINTERPRETER_HPP_

#include <libpq-fe.h>
#include <vector>
#include <firefly/core/model/beans/Point3DBean.hpp>
#include <firefly/core/model/interpreters/PGResultInterpreter.hpp>

namespace firefly {
class Point3DInterpreter : public PGResultInterpreter {
 public:
    using PGResultInterpreter::PGResultInterpreter;

    explicit Point3DInterpreter(PGresult *result);

    Point3DBean getPoint3D(int row);

 private:
    const std::vector<const char *> PROPERTIES();
};
}  // namespace firefly

#endif  // FIREFLY_CORE_INCLUDE_FIREFLY_CORE_MODEL_INTERPRETERS_POINT3DINTERPRETER_HPP_
