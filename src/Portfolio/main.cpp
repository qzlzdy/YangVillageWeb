#include "Portfolio/Portfolio.h"

using namespace std;
using namespace Wt;
using namespace yang;

int main(int argc, char **argv){
    return WRun(argc, argv, [](const WEnvironment &env){
        return make_unique<Portfolio>(env);
    });
}
