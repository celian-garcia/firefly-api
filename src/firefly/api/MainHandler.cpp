// Copyright 2017 <Célian Garcia>

#include <firefly/utils/ModuleAction.hpp>
#include <firefly/utils/ModuleName.hpp>
#include "firefly/api/MainHandler.hpp"

namespace firefly {

    MainHandler::MainHandler(HttpServer *server, const path &resources_path, int nb_threads) {
        this->m_pool = new ThreadPool(nb_threads);
        this->m_server = server;
        this->m_resources_path = resources_path;
        this->initDefaultResource();
        this->initModulesResources();
    }

    void
    MainHandler::initModulesResources() {
        this->m_server->resource["^/api/module/(\\w+)/(\\w+)$"]["GET"] = [this](std::shared_ptr<HttpResponse> response,
                                                                                std::shared_ptr<HttpRequest> request) {
            try {
                std::string raw_module_name = request->path_match[1];
                std::string raw_module_action = request->path_match[2];
                ModuleName module_name(raw_module_name);
                ModuleAction module_action(raw_module_action);
                IModuleHandler *handler;
                switch (module_name.getType()) {
                    case ModuleType::RECONSTRUCTION3D:
                        handler = new module_fly::FlyHandler(module_fly::FlyRequestType::RECONSTRUCT_3D, module_action);
                    case ModuleType::CLOUDPOPULATION3D:
                        handler = new module_fly::FlyHandler(module_fly::FlyRequestType::POPULATE_3D, module_action);
                    case ModuleType::CVFILTERGAUSSIAN:
                        throw FireflyException(HtmlStatusCode::NOT_IMPLEMENTED, "Not yet implemented");
                    case ModuleType::OPOPOLOP:
                        throw FireflyException(HtmlStatusCode::NOT_IMPLEMENTED,
                                               "Not yet implemented (probably never)");
                    default:
                        throw FireflyException(HtmlStatusCode::BAD_REQUEST,
                                               module_name.getValue() + " module does not exist.");
                }
                handler->handleRequest(response, request);
            }
            catch (const FireflyException &exception) {
                exception.sendError(response);
            }
        };
    }

    void
    MainHandler::initDefaultResource() {
        // Default GET-example. If no other matches, this anonymous function will be called.
        // Will respond with content in the web/-directory, and its subdirectories.
        // Default file: index.html
        // Can for instance be used to retrieve an HTML 5 client that uses REST-resources on this server
        this->m_server->default_resource["GET"] = [this]
                (std::shared_ptr<HttpResponse> response, std::shared_ptr<HttpRequest> request) {
            try {
                // Build the absolute path from request
                auto path = boost::filesystem::canonical(this->m_resources_path / request->path);

                // Check the path
                long long int resources_path_len = std::distance(
                        this->m_resources_path.begin(), this->m_resources_path.end());
                long long int path_len = std::distance(path.begin(), path.end());
                if (resources_path_len > path_len ||
                    !std::equal(this->m_resources_path.begin(), this->m_resources_path.end(), path.begin()))
                    throw std::invalid_argument("path must be within root path");
                if (boost::filesystem::is_directory(path))
                    path /= "index.html";
                if (!(boost::filesystem::exists(path) && boost::filesystem::is_regular_file(path)))
                    throw std::invalid_argument("file does not exist");
                std::cout << path << std::endl;

                // Read the corresponding file and send it back to the client
                auto ifs = std::make_shared<std::ifstream>();
                ifs->open(path.string(), std::ifstream::in | std::ios::binary);

                if (*ifs) {
                    ifs->seekg(0, std::ios::end);
                    auto length = ifs->tellg();

                    ifs->seekg(0, std::ios::beg);

                    *response << "HTTP/1.1 200 OK\r\nContent-Length: " << length << "\r\n\r\n";
                    this->sendDefaultResource(response, ifs);
                } else {
                    throw std::invalid_argument("could not read file");
                }
            }
            catch (const FireflyException &e) {
                e.sendError(response);
            }
            catch (const std::exception &e) {
                std::string content = "Could not open path " + request->path + ": " + e.what();
                FireflyException(HtmlStatusCode::BAD_REQUEST, content).sendError(response);
            }
        };
    }

/// read and send 128 KB at a time
/// Safe when server is running on one thread
    void
    MainHandler::sendDefaultResource(
            const std::shared_ptr<HttpResponse> &response,
            const std::shared_ptr<std::ifstream> &ifs) {

        static std::vector<char> buffer(131072);
        std::streamsize read_length;
        if ((read_length = ifs->read(&buffer[0], buffer.size()).gcount()) > 0) {
            response->write(&buffer[0], read_length);
            if (read_length == static_cast<std::streamsize>(buffer.size())) {
                this->m_server->send(response, [this, response, ifs](const boost::system::error_code &ec) {
                    if (!ec)
                        this->sendDefaultResource(response, ifs);
                    else
                        std::cerr << "Connection interrupted" << std::endl;
                });
            }
        }
    }

}  // end namespace firefly
