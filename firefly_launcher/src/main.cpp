/// Copyright 2017 <Célian Garcia>
#include <firefly/core/server/Server.hpp>
#include <firefly/core/config/DataCommonStore.hpp>

#ifdef WITH_FLY_MODULE
#include "fly_module/data/FlyModule.hpp"
#endif
//#ifdef WITH_CV_MODULE
//#include "cv_module/api/CvHandler.hpp"
//#endif

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: Firefly.exe <port> <web_root> <nb_thread>\n";
        return 1;
    }

    unsigned short port = (unsigned short)atoi(argv[1]);
    boost::filesystem::path resources_path = boost::filesystem::canonical(argv[2]);
    int nb_threads = atoi(argv[3]);

    firefly::DataCommonStore dataStore;
    firefly::Server server(port, resources_path, dataStore);

#ifdef WITH_FLY_MODULE
    firefly::Module module = firefly::FlyModule();
    server.registerModule(module);
#endif
    std::cerr << "Server successfully initialized\n";

    server.run();


    return 0;
}


