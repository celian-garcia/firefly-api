// Copyright 2017 <Célian Garcia>

#include "fly_module/api/FlyHandler.hpp"

namespace firefly {
    namespace fly_module {

        FlyHandler::FlyHandler(Process process, ProcessAction action, QueryParameters parameters, ThreadPool *pool) :
                m_process(process), m_action(action), m_parameters(parameters), m_pool(pool) {}

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
                    int process_id = FlyCloudPopulation::start(this->m_pool);
                    json result_content;
                    result_content["process_id"] = process_id;
                    result_content["status"] = 0;

                    // TODO(Célian): externalize build of response
                    std::string content = result_content.dump();
                    *response << "HTTP/1.1 200 \r\n";
                    *response << "Content-Length: " << content.length() << "\r\n\r\n";
                    *response << content;
                    break;
                }
                case ProcessActionType::STOP: {
                    FlyCloudPopulation::stop();
                    break;
                }
                case ProcessActionType::COLLECT: {
                    try {
                        int process_id = std::stoi(this->m_parameters["process_id"]);
                        int client_last_op = std::stoi(this->m_parameters["status"]);
                        std::vector<Operation> operations_list = FlyCloudPopulation::collect(process_id, client_last_op);

                        json result_content = operations_list;

                        // TODO(Célian): externalize build of response
                        std::string content = result_content.dump();
                        *response << "HTTP/1.1 200 \r\n";
                        *response << "Content-Length: " << content.length() << "\r\n\r\n";
                        *response << content;
                    }
                    catch (std::invalid_argument exception) {
                        throw FireflyException(HtmlStatusCode::BAD_REQUEST, "Bad Request");
                    }
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
    }  // end namespace fly_module
}  // end namespace firefly
