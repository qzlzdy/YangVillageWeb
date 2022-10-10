#include "Portfolio.h"

#include <Wt/WBootstrap5Theme.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLink.h>
#include <Wt/WVBoxLayout.h>
#include "About.h"
#include "Contact.h"
#include "Footer.h"
#include "Header.h"
#include "Home.h"
#include "Resume.h"
#include "Skills.h"

using namespace std;
using namespace Wt;
using namespace yang;

namespace {

const WLink BootstrapIcon = "https://cdn.jsdelivr.net/npm/"
    "bootstrap-icons@1.9.1/font/bootstrap-icons.css";

}

Portfolio::Portfolio(const WEnvironment &env): WApplication(env){
    // if(env.urlScheme() != "https"){
    //     redirect("https://" + env.hostName() + url());
    //     return;
    // }
    setTheme(make_shared<WBootstrap5Theme>());
    useStyleSheet(BootstrapIcon);
    setTitle("羊村");

    WContainerWidget *contents =
        root()->addWidget(make_unique<WContainerWidget>());
    contents->setStyleClass("p-0");
    WVBoxLayout *main = contents->setLayout(make_unique<WVBoxLayout>());
    main->addWidget(make_unique<Home>());
    main->addWidget(make_unique<About>());
    main->addWidget(make_unique<Skills>());
    main->addWidget(make_unique<Resume>());
    main->addWidget(make_unique<Contact>());

    root()->addWidget(make_unique<Header>());
    root()->addWidget(make_unique<Footer>());
}
