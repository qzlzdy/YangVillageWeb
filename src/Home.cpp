#include "Home.h"

#include <Wt/WText.h>

using namespace std;
using namespace Wt;
using namespace yang;

Home::Home(){
    addWidget(make_unique<WText>("Hello World"));
}
