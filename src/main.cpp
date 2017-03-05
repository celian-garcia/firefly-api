/// Copyright 2017 <Célian Garcia>
#include "firefly/server_http.hpp"
#include "firefly/api/MainHandler.hpp"

typedef SimpleWeb::Server<SimpleWeb::HTTP> HttpServer;

using firefly::MainHandler;

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: Firefly.exe <port> <web_root> <nb_thread>\n";
        return 1;
    }

    int port = atoi(argv[1]);
    boost::filesystem::path resources_path = boost::filesystem::canonical(argv[2]);
    int nb_threads = atoi(argv[3]);

    HttpServer server(port, 1);

    MainHandler main_handler(&server, resources_path, nb_threads);

    // HTTP-server at port 8080 using 1 thread
    // Unless you do more heavy non-threaded processing in the resources,
    // 1 thread is usually faster than several threads

    std::cout
        << "Server started successfully !"
        << ". \n=== Port: \""
        << port
        << ". \n=== Web root path: \""
        << resources_path
        << ". \n=== Number of threads: \""
        << nb_threads
        << "\""
        << std::endl;

    boost::thread server_thread([&server](){
        //Start server
        server.start();
    });

    server_thread.join();

    return 0;
}


