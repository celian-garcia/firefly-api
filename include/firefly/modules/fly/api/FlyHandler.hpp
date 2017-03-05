// Copyright 2017 <Célian Garcia>

#ifndef INCLUDE_FIREFLY_MODULES_FLY_API_FLYHANDLER_HPP_
#define INCLUDE_FIREFLY_MODULES_FLY_API_FLYHANDLER_HPP_

#include <string>
#include "firefly/api/IModuleHandler.hpp"
#include "firefly/utils/server_types_definitions.hpp"
#include <firefly/utils/FireflyException.hpp>
#include <firefly/utils/ModuleAction.hpp>

namespace firefly {
    namespace module_fly {
        enum FlyRequestType {
            RECONSTRUCT_3D, POPULATE_3D
        };

        class FlyHandler : public firefly::IModuleHandler {
        public:
            FlyHandler(FlyRequestType type, ModuleAction action);

            ///
            /// \param response
            /// \param request
            void handleRequest(std::shared_ptr<HttpResponse> response, std::shared_ptr<HttpRequest> request);

        private:
            FlyRequestType m_type;
            ModuleAction m_action;
        };

    }  // end namespace module_fly
}  // end namespace firefly
#endif  // INCLUDE_FIREFLY_MODULES_FLY_API_FLYHANDLER_HPP_
