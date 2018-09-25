// Copyright 2017 <Célian Garcia>

#include <firefly/server/Server.hpp>

namespace firefly {

Server::Server(const ServerConfig& srv_config, const DatabaseConfig& db_config, const DataCommonStore& data_store) :
        server(srv_config.port, 1), srv_config(srv_config), db_config(db_config), data_store(data_store) {}

void Server::run() {
    this->initDefaultResource();
    this->initializeFireflyResources();
    boost::thread server_thread([this]() {
        // Start server
        this->server.start();
    });

    server_thread.join();
}

std::function<void(
        std::shared_ptr<SimpleWeb::ServerBase<SimpleWeb::HTTP>::Response>,
        std::shared_ptr<SimpleWeb::ServerBase<SimpleWeb::HTTP>::Request>)>
Server::buildFireflyResource(
        const std::function<void(std::shared_ptr<SimpleWeb::ServerBase<SimpleWeb::HTTP>::Response>,
                                 std::shared_ptr<SimpleWeb::ServerBase<SimpleWeb::HTTP>::Request>)> &resource) {
    return [resource](
            std::shared_ptr<HttpResponse> response,
            std::shared_ptr<HttpRequest> request) -> void {
        try {
            resource(response, request);
        } catch (const FireflyException &e) {
            e.sendError(response);
        } catch (const std::exception &e) {
            FireflyException(HtmlStatusCode::INTERNAL_SERVER_ERROR, e.what()).sendError(response);
        }
    };
}

void Server::initializeFireflyResources() {
    this->server.resource["^/api/v1/modules$"]["GET"] = buildFireflyResource([this](
            std::shared_ptr<HttpResponse> response,
            std::shared_ptr<HttpRequest> request) -> void {
        nlohmann::json result_content(this->data_store.getModules());
        ResponseBuilder::build(result_content, response);
    });

    this->server.resource["^/api/v1/tasks$"]["GET"] = buildFireflyResource([this](
            std::shared_ptr<HttpResponse> response,
            std::shared_ptr<HttpRequest> request) {
        nlohmann::json result_content = nlohmann::json::array();

        DatabaseManager* db_manager = buildDatabaseManager();
        TaskModel taskModel(db_manager, data_store);

        for (auto task : taskModel.getTasks()) {
            result_content.push_back(task);
        }

        delete db_manager;
        ResponseBuilder::build(result_content, response);
    });

    this->server.resource["^/api/v1/tasks$"]["DELETE"] = buildFireflyResource([this](
            std::shared_ptr<HttpResponse> response,
            std::shared_ptr<HttpRequest> request) {
        nlohmann::json result_content;

        DatabaseManager* db_manager = buildDatabaseManager();
        TaskModel taskModel(db_manager, data_store);
        result_content = taskModel.clearAllTasks();

        delete db_manager;
        ResponseBuilder::build(result_content, response);
    });

    this->server.resource["^/api/v1/tasks$"]["POST"] = buildFireflyResource([this](
            std::shared_ptr<HttpResponse> response,
            std::shared_ptr<HttpRequest> request) -> void {
        TaskBuilder taskBuilder = nlohmann::json::parse(request->content);
        Task task = taskBuilder.buildTask(this->data_store);

        DatabaseManager* db_manager = buildDatabaseManager();
        TaskModel taskModel(db_manager);
        nlohmann::json resultTask = taskModel.insertTask(task);

        delete db_manager;
        ResponseBuilder::build(resultTask, response);
    });

    this->server.resource["^/api/v1/tasks/([0-9]+)$"]["GET"] = buildFireflyResource([this](
            std::shared_ptr<HttpResponse> response,
            std::shared_ptr<HttpRequest> request) -> void {
        std::string task_id = request->path_match[1];

        DatabaseManager* db_manager = buildDatabaseManager();
        TaskModel taskModel(db_manager, data_store);
        const std::optional<Task> &resultTask = taskModel.getTaskById(atoi(task_id.c_str()));

        delete db_manager;
        if (resultTask) {
            ResponseBuilder::build(static_cast<nlohmann::json>(resultTask.value()), response);
        } else {
            ResponseBuilder::build("{}", response);
        }
    });

    this->server.resource["^/api/v1/tasks/([0-9]+)/run$"]["POST"] = buildFireflyResource([this](
            std::shared_ptr<HttpResponse> response,
            std::shared_ptr<HttpRequest> request) -> void {
        std::string task_id = request->path_match[1];
        DatabaseManager* db_manager = buildDatabaseManager();
        TaskModel taskModel(db_manager, data_store);
        const std::optional<Task> &resultTask = taskModel.getTaskById(atoi(task_id.c_str()));

        delete db_manager;
        if (resultTask) {
            Task task = resultTask.value();
            ProcessingType task_type = task.getType();
            int module_id = task.getModule().getId();
            fly_module::FlyCloudPopulation action(this->db_config.host, this->db_config.port,
                    this->db_config.database, this->db_config.user, this->db_config.password);
            action.start(task.getIdentifier(), thread_pool_map[module_id], task_type);
            ResponseBuilder::build("{\"resultOk\": true}", response);
        } else {
            ResponseBuilder::build("{\"resultOk\": false}", response);
        }
    });

    this->server.resource["^/api/v1/tasks/([0-9]+)/operations/([0-9]+)$"]["GET"] = buildFireflyResource([this](
            std::shared_ptr<HttpResponse> response,
            std::shared_ptr<HttpRequest> request) -> void {
        int task_id = std::stoi(request->path_match[1]);
        int client_last_op = std::stoi(request->path_match[2]);

        // Get the last operations since the one given by client
        DatabaseManager* db_manager = buildDatabaseManager();
        OperationModel operation_model(db_manager);
        std::vector<Operation> operations_list = operation_model.getOperationsSince(task_id, client_last_op);
        delete db_manager;

        // Compute the new operation index
        int last_operation_index = 0;
        if (!operations_list.empty()) {
            last_operation_index = std::max_element(
                    operations_list.begin(),
                    operations_list.end(),
                    [](auto op1, auto op2) { return op1.getId() < op2.getId(); })->getId();
        }

        nlohmann::json result_content = nlohmann::json{
                {"lastOperationIndex", last_operation_index},
                {"operations",         operations_list}};

        ResponseBuilder::build(result_content, response);
    });
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
            auto path = boost::filesystem::canonical(this->srv_config.resources_path / request->path);

            // Check the path
            int64 resources_path_len = std::distance(
                    this->srv_config.resources_path.begin(), this->srv_config.resources_path.end());
            int64 path_len = std::distance(path.begin(), path.end());
            if (resources_path_len > path_len ||
                !std::equal(this->srv_config.resources_path.begin(),
                        this->srv_config.resources_path.end(), path.begin()))
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

void Server::registerModule(Module *module, ThreadPool *pool) {
    this->data_store.storeModule(module);
    this->thread_pool_map[module->getId()] = pool;
}

DatabaseManager *Server::buildDatabaseManager() {
    return new DatabaseManager(this->db_config.host, this->db_config.port, this->db_config.database,
                               this->db_config.user, this->db_config.password);
}

}  // namespace firefly
