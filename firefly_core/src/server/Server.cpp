// Copyright 2017 <Célian Garcia>

#include "firefly/core/server/Server.hpp"

using namespace std::literals::string_literals;

namespace firefly {

    Server::Server(unsigned short port, boost::filesystem::path resources_path) :
            server(port, 1), modules_list(), resources_path(resources_path) {}

    void Server::run() {
        this->initDefaultResource();
        this->initializeFireflyResources();
        boost::thread server_thread([this]() {
            //Start server
            this->server.start();
        });

        server_thread.join();
    }

//    void Server::initializeModuleResources(Module module) {
//        std::string moduleEndpoint = Server::buildModuleApiEndpoint(module);
//        std::string processingsUri = moduleEndpoint + "/processings"s;
//        for (auto &processing : module.getProcessingTypesList()) {
//            for (auto &resource : processing.getActions()) {
//                this->registerProcessingAction(processingsUri, resource);
//            }
//        }
//    }

//    void Server::registerProcessingAction(std::string processingsUri, ProcessingAction processingAction) {
//        std::string queryPath =
//                processingsUri + "/"s + processingAction.getProcessingId() + "/"s + processingAction.getName();
//
//        this->server.resource[queryPath + "(\\?.*)?"s][processingAction.getHttpMethod()] = [processingAction](
//                std::shared_ptr<HttpResponse> response,
//                std::shared_ptr<HttpRequest> request) {
//            request->content
//            json postData;
//            std::string query_string = request->path_match[1];
//            QueryParameters queryParameters(query_string);
//            processingAction.run(queryParameters, postData);
//        };
//    }

//    std::string Server::buildFireflyApiEndpoint() {
//        return "api/v"s + Server::API_VERSION;
//    }
//
//    std::string Server::buildModuleApiEndpoint(Module module) {
//        std::string endpoint = "modules/";
//        return "modules/"s + module.getId() + "/api/v"s + module.getVersion();
//    }

//    std::string Server::buildProcessingUri(std::string moduleApiEndpoint, Task processing) {
//        return moduleApiEndpoint + "/"s +
//    }

    void Server::initializeFireflyResources() {
        this->server.resource["^/firefly/modules$"]["GET"] = [this](
                std::shared_ptr<HttpResponse> response,
                std::shared_ptr<HttpRequest> request) {

            json result_content;

            for (auto module : this->modules_list) {
                result_content.push_back(module);
            }

            ResponseBuilder::build(result_content, response);
        };

        this->server.resource["^/api/v1/tasks"]["GET"] = [this](
                std::shared_ptr<HttpResponse> response,
                std::shared_ptr<HttpRequest> request) {

            json result_content;

            std::vector<std::string> aliases{"alias1", "alias2"};
            ProcessingType pt("proctypetest", aliases);
            Task p1("test1title", "test1description", pt);
            Task p2("test2title", "test2description", pt);
            Task p3("test3title", "test3description", pt);
            result_content.push_back(p1);
            result_content.push_back(p2);
            result_content.push_back(p3);

            ResponseBuilder::build(result_content, response);
        };

        this->server.resource["^/api/v1/names"]["GET"] = [this](
                std::shared_ptr<HttpResponse> response,
                std::shared_ptr<HttpRequest> request) {

            json result_content{"name1", "name2"};
            ResponseBuilder::build(result_content, response);
        };

        this->server.resource["^/api/v1/categories"]["GET"] = [this](
                std::shared_ptr<HttpResponse> response,
                std::shared_ptr<HttpRequest> request) {

            json result_content{"category1", "category2"};
            ResponseBuilder::build(result_content, response);
        };
    }

    void
    Server::initDefaultResource() {
        // Default GET-example. If no other matches, this anonymous function will be called.
        // Will respond with content in the web/-directory, and its subdirectories.
        // Default file: index.html
        // Can for instance be used to retrieve an HTML 5 client that uses REST-resources on this server
        this->server.default_resource["GET"] = [this]
                (std::shared_ptr<HttpResponse> response, std::shared_ptr<HttpRequest> request) {
            try {
                // Build the absolute path from request
                auto path = boost::filesystem::canonical(this->resources_path / request->path);

                // Check the path
                long long int resources_path_len = std::distance(
                        this->resources_path.begin(), this->resources_path.end());
                long long int path_len = std::distance(path.begin(), path.end());
                if (resources_path_len > path_len ||
                    !std::equal(this->resources_path.begin(), this->resources_path.end(), path.begin()))
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
    Server::sendDefaultResource(
            const std::shared_ptr<HttpResponse> &response,
            const std::shared_ptr<std::ifstream> &ifs) {

        static std::vector<char> buffer(131072);
        std::streamsize read_length;
        if ((read_length = ifs->read(&buffer[0], buffer.size()).gcount()) > 0) {
            response->write(&buffer[0], read_length);
            if (read_length == static_cast<std::streamsize>(buffer.size())) {
                this->server.send(response, [this, response, ifs](const boost::system::error_code &ec) {
                    if (!ec)
                        this->sendDefaultResource(response, ifs);
                    else
                        std::cerr << "Connection interrupted" << std::endl;
                });
            }
        }
    }

    void Server::registerModule(Module module) {
        this->modules_list.push_back(module);
    };

}
