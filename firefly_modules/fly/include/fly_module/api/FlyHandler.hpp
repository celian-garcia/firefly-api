// Copyright 2017 <Célian Garcia>

#ifndef INCLUDE_FIREFLY_MODULES_FLY_API_FLYHANDLER_HPP_
#define INCLUDE_FIREFLY_MODULES_FLY_API_FLYHANDLER_HPP_

#include <string>
#include <vector>
#include "firefly/api/IModuleHandler.hpp"
#include "firefly/utils/server_types_definitions.hpp"
#include <firefly/utils/FireflyException.hpp>
#include <firefly/utils/ProcessAction.hpp>
#include <firefly/utils/Process.hpp>
#include <firefly/modules/fly/workers/FlyCloudPopulation.hpp>
#include <json/json.hpp>
#include <boost/exception/info.hpp>
#include <firefly/utils/ThreadPool.hpp>
#include <firefly/utils/QueryParameters.hpp>

namespace firefly {
    namespace fly_module {
        class FlyHandler : public firefly::IModuleHandler {
            using json = nlohmann::json;
        public:
            FlyHandler(Process process, ProcessAction action, QueryParameters parameters, ThreadPool *pool);

            ///
            /// \param response
            /// \param request
            void handleRequest(std::shared_ptr<HttpResponse> response, std::shared_ptr<HttpRequest> request);

            void handleP3DRequest(std::shared_ptr<HttpResponse> response, std::shared_ptr<HttpRequest> request);

            void handleR3DRequest(std::shared_ptr<HttpResponse> response, std::shared_ptr<HttpRequest> request);

        private:
            Process m_process;
            ProcessAction m_action;
            QueryParameters m_parameters;
            ThreadPool *m_pool;
        };

    }  // end namespace fly_module
}  // end namespace firefly
#endif  // INCLUDE_FIREFLY_MODULES_FLY_API_FLYHANDLER_HPP_
