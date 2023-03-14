#include "Homepage/Homepage.h"
#include "Portfolio/Portfolio.h"

#include <csignal>
#include <Wt/WServer.h>

using namespace std;
using namespace Wt;
using namespace yang;

int main(int argc, char **argv){
    try{
        WServer server(argv[0]);
        server.setServerConfiguration(argc, argv, WTHTTP_CONFIGURATION);
        server.addEntryPoint(Wt::EntryPointType::Application,
            [](const WEnvironment &env){
                return make_unique<Homepage>(env);
            }, "", "favicon.ico");
        server.addEntryPoint(Wt::EntryPointType::Application,
            [](const WEnvironment &env){
                return make_unique<Portfolio>(env);
            }, "/portfolio", "favicon.ico");
        if(server.start()){
            int sig = WServer::waitForShutdown();
            cerr << "Shutdown (signal = " << sig << ")" << endl;
            server.stop();
            if(sig == SIGHUP){
                server.restart(argc, argv, environ);
            }
        }
    }
    catch(WServer::Exception &e){
        cerr << e.what() << endl;
        return 1;
    }
    catch(exception &e){
        cerr << "exception: " << e.what() << endl;
        return 1;
    }
    return 0;
}
