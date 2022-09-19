#include "Portfolio.h"

#include <Wt/WBootstrap5Theme.h>
#include "Header.h"

using namespace std;
using namespace Wt;
using namespace yang;

Portfolio::Portfolio(const WEnvironment &env): WApplication(env){
    // if(env.urlScheme() != "https"){
    //     redirect("https://" + env.hostName() + url());
    //     return;
    // }
    setTheme(make_shared<WBootstrap5Theme>());
    useStyleSheet("https://cdn.jsdelivr.net/npm/bootstrap-icons@1.9.1/font/bootstrap-icons.css");
    setTitle("羊村");
    root()->addWidget(make_unique<Header>());
}
