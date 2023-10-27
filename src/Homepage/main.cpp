#include <memory>
#include <Wt/WApplication.h>
#include <Wt/WEnvironment.h>
#include "Homepage/Homepage.h"

using namespace std;
using namespace Wt;
using namespace yang;

int main(int argc, char **argv){
    return WRun(argc, argv, [](const WEnvironment &env){
        return make_unique<Homepage>(env);
    });
}
