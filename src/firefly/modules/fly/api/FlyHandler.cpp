// Copyright 2017 <Célian Garcia>

#include "firefly/modules/fly/api/FlyHandler.hpp"

namespace firefly {
    namespace module_fly {

        FlyHandler::FlyHandler(FlyRequestType type, ModuleAction action) : m_type(type), m_action(action) {}

        void
        FlyHandler::handleRequest(std::shared_ptr<HttpResponse> response, std::shared_ptr<HttpRequest> request) {
            switch (this->m_type) {
                case FlyRequestType::RECONSTRUCT_3D:
                    // TODO: - parses the input from request
                    // TODO: - gives them to the good worker (the action is given here to control the capability of the worker)
                    // TODO: - retrieves from the worker the immediate answer
                    // TODO: - Give it back to the response (ie the client)
                    throw  FireflyException(HtmlStatusCode::NOT_IMPLEMENTED, "3D reconstruction not yet implemented");
                case FlyRequestType::POPULATE_3D:
                    throw  FireflyException(HtmlStatusCode::NOT_IMPLEMENTED, "3D population not yet implemented");
                default:
                    throw  FireflyException(HtmlStatusCode::INTERNAL_SERVER_ERROR, "Fly does not know this type of request");
            }
        }
    }  // end namespace module_fly
}  // end namespace firefly
