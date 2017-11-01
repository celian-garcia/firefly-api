//
// Created by root on 14/10/17.
//

#ifndef FIREFLY_POINT3DINTERPRETER_H
#define FIREFLY_POINT3DINTERPRETER_H

#include <libpq-fe.h>
#include <vector>
#include <firefly/core/model/beans/Point3DBean.hpp>
#include <firefly/core/model/PGResultInterpreter.hpp>

namespace firefly {
    namespace fly_module {
        class Point3DInterpreter {
        public:
            explicit Point3DInterpreter(PGresult *result);

            virtual ~Point3DInterpreter();

            Point3DBean getPoint3D(int row);

            int get_row_number();

        private:
            static const std::vector<const char *> PROPERTIES();

            PGResultInterpreter *interpreter;

        };
    }
}




#endif //FIREFLY_POINT3DINTERPRETER_H
