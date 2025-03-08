/*    YangVillage Website
 *    Copyright (C) 2024  Qzlzdy
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU Affero General Public License as published
 *    by the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Affero General Public License for more details.
 *
 *    You should have received a copy of the GNU Affero General Public License
 *    along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
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
