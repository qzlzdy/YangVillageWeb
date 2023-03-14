#include "Homepage/Homepage.h"

using namespace Wt;
using namespace yang;

Homepage::Homepage(const WEnvironment &env): WApplication(env){
    redirect("https://" + env.hostName() + "/portfolio");
}
