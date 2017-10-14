// Copyright 2017 <Célian Garcia>

#include <thread>
#include <firefly/server/Server.hpp>
#include <fly_module/workers/FlyCloudPopulation.hpp>

using namespace std::literals::string_literals;

namespace firefly {

    Server::Server(unsigned short port, boost::filesystem::path resources_path, DataCommonStore dataStore) :
            server(port, 1), resources_path(resources_path), dataStore(dataStore){}

    void Server::run() {
        this->initDefaultResource();
        this->initializeFireflyResources();
        boost::thread server_thread([this]() {
            //Start server
            this->server.start();
        });

        server_thread.join();
    }

    void Server::initializeFireflyResources() {
        this->server.resource["^/api/v1/modules$"]["GET"] = [this](
                std::shared_ptr<HttpResponse> response,
                std::shared_ptr<HttpRequest> request) {
            std::cout<<"api/v1/modules endpoint reached\n"<<std::endl;
            json result_content(this->dataStore.getModules());
            ResponseBuilder::build(result_content, response);
        };

        this->server.resource["^/api/v1/tasks$"]["GET"] = [this](
                std::shared_ptr<HttpResponse> response,
                std::shared_ptr<HttpRequest> request) {
            std::cout<<"api/v1/tasks endpoint reached\n"<<std::endl;
            json result_content;

            const std::vector<std::string> &aliases{"alias1", "alias2"};
            ProcessingType pt("proctypetest", aliases);
            std::string lorem = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
            Module m;
            m.setName("FLY");
            Task p1(1, "Création d'un nuage de points 3D aléatoires", lorem, pt, m, "celgarcia", "2012-04-23T18:25:43.511Z");
            Task p2(2, "Création d'un nuage de points 3D aléatoires", lorem, pt, m, "celgarcia", "2012-04-23T18:25:43.511Z");
            Task p3(3, "Création d'un nuage de points 3D aléatoires", lorem, pt, m, "celgarcia", "2012-04-23T18:25:43.511Z");
            Task p4(4, "Création d'un nuage de points 3D aléatoires", lorem, pt, m, "celgarcia", "2012-04-23T18:25:43.511Z");
            Task p5(5, "Création d'un nuage de points 3D aléatoires", lorem, pt, m, "celgarcia", "2012-04-23T18:25:43.511Z");
            p1.setState(Task::CREATED);
            p2.setState(Task::STARTED);
            p3.setState(Task::PAUSED);
            p4.setState(Task::FINISHED);
            p5.setState(Task::ABORTED);
            result_content.push_back(p1);
            result_content.push_back(p2);
            result_content.push_back(p3);
            result_content.push_back(p4);
            result_content.push_back(p5);
            DatabaseManager db_manager("firefly_hive");
            TaskModel taskModel(&db_manager, dataStore);
            for (auto task : taskModel.getTasks()) {
                result_content.push_back(task);
            }
            std::cout<<result_content<<"\n"<<std::endl;

            ResponseBuilder::build(result_content, response);
        };

        this->server.resource["^/api/v1/tasks$"]["POST"] = [this](
                std::shared_ptr<HttpResponse> response,
                std::shared_ptr<HttpRequest> request) {
            TaskBuilder taskBuilder = json::parse(request->content);
            Task task = taskBuilder.buildTask(this->dataStore);
            DatabaseManager db_manager("firefly_hive");
            TaskModel taskModel(&db_manager);
            json resultTask = taskModel.insertTask(task);
            ResponseBuilder::build(resultTask, response);
        };

        this->server.resource["^/api/v1/tasks/([0-9]+)$"]["GET"] = [this](
                std::shared_ptr<HttpResponse> response,
                std::shared_ptr<HttpRequest> request) {

            std::string task_id = request->path_match[1];

            DatabaseManager db_manager("firefly_hive");
            TaskModel taskModel(&db_manager, dataStore);
            const std::optional<Task> &resultTask = taskModel.getTaskById(atoi(task_id.c_str()));
            if (resultTask) {
                ResponseBuilder::build(static_cast<json>(resultTask.value()), response);
            }
            else {
                ResponseBuilder::build("{}", response);
            }
        };

        this->server.resource["^/api/v1/tasks/([0-9]+)/run"]["POST"] = [this](
                std::shared_ptr<HttpResponse> response,
                std::shared_ptr<HttpRequest> request) {
            std::string task_id = request->path_match[1];
            DatabaseManager db_manager("firefly_hive");
            TaskModel taskModel(&db_manager, dataStore);
            const std::optional<Task> &resultTask = taskModel.getTaskById(atoi(task_id.c_str()));
            if (resultTask) {
                Task task = resultTask.value();
                int module_id = task.getModule().getId();
                fly_module::FlyCloudPopulation::start(thread_pool_map[module_id]);
                ResponseBuilder::build("{\"resultOk\": true}", response);
            } else {
                ResponseBuilder::build("{\"resultOk\": false}", response);
            }
        };

        this->server.resource["^/api/v1/tasks/([0-9]+)/progress/([0-9]+)$"]["GET"] = [this](
                std::shared_ptr<HttpResponse> response,
                std::shared_ptr<HttpRequest> request) {
            std::string task_id = request->path_match[1];
            std::string progress_id = request->path_match[2];
            json result_content{"task_id", "progress_id"};
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

    void Server::registerModule(Module& module, ThreadPool* pool) {
        this->dataStore.storeModule(module);
        this->thread_pool_map[module.getId()] = pool;
    }

}
