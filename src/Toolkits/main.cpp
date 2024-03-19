#include "Toolkits/Echo.h"

#include <csignal>
#include <Wt/WServer.h>

using namespace std;
using namespace Wt;
using namespace yang;

int main(int argc, char *argv[]){
    try{
        WServer server(argv[0]);
        server.setServerConfiguration(argc, argv);
        server.addResource(make_shared<Echo>(), "/echo");
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
        return -1;
    }
    catch(exception &e){
        cerr << "exception: " << e.what() << endl;
        return -1;
    }
    return 0;
}
