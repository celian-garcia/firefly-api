// Copyright 2017 <Célian Garcia>

#include <boost/exception/info.hpp>
#include "firefly/modules/fly/api/FlyHandler.hpp"

namespace firefly {
    namespace module_fly {

        FlyHandler::FlyHandler(Process process, ProcessAction action) : m_process(process), m_action(action) {}

        void
        FlyHandler::handleRequest(std::shared_ptr<HttpResponse> response, std::shared_ptr<HttpRequest> request) {
            switch (this->m_process.getProcessType()) {
                case ProcessType::FLY_R3D: {
                    this->handleR3DRequest(response, request);
                    break;
                }
                case ProcessType::FLY_P3D: {
                    this->handleP3DRequest(response, request);
                    break;
                }
                default: {
                    throw FireflyException(HtmlStatusCode::INTERNAL_SERVER_ERROR,
                                           "Fly does not know this type of request");
                }
            }
        }

        void
        FlyHandler::handleP3DRequest(std::shared_ptr<HttpResponse> response, std::shared_ptr<HttpRequest> request) {
            switch (this->m_action.getActionType()) {
                case ProcessActionType::START: {
                    int process_id = FlyCloudPopulation::start();
                    json result_content;
                    result_content["process_id"] = process_id;

                    // TODO(Célian): externalize build of response
                    std::string content = result_content.dump();
                    *response << "HTTP/1.1 200 \r\n";
                    *response << "Content-Length: " << content.length() << "\r\n\r\n";
                    *response << content;
                    break;
                }
                case ProcessActionType::STOP:{
                    FlyCloudPopulation::stop();
                    break;
                }
                case ProcessActionType::COLLECT:{
                    FlyCloudPopulation::collect();
                    break;
                }
                default: {
                    throw FireflyException(HtmlStatusCode::NOT_IMPLEMENTED, "Not yet implemented");
                }
            }
        }

        void
        FlyHandler::handleR3DRequest(std::shared_ptr<HttpResponse> response, std::shared_ptr<HttpRequest> request) {
            throw FireflyException(HtmlStatusCode::NOT_IMPLEMENTED, "3D reconstruction not yet implemented");
        }
    }  // end namespace module_fly
}  // end namespace firefly
