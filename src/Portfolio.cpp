#include "Portfolio.h"

#include <Wt/WBootstrap5Theme.h>
#include <Wt/WString.h>
#include "Footer.h"
#include "Header.h"

using namespace std;
using namespace Wt;
using namespace yang;

namespace {

const WLink BootstrapIcon = "https://cdn.jsdelivr.net/"
    "npm/bootstrap-icons@1.9.1/font/bootstrap-icons.css";

}

Portfolio::Portfolio(const WEnvironment &env): WApplication(env){
    // if(env.urlScheme() != "https"){
    //     redirect("https://" + env.hostName() + url());
    //     return;
    // }
    setTheme(make_shared<WBootstrap5Theme>());
    useStyleSheet(BootstrapIcon);
    setTitle("羊村");
    root()->addWidget(make_unique<Header>());
    root()->addWidget(make_unique<Footer>());
}
