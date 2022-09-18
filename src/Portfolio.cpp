#include "Portfolio.h"

#include <Wt/WBootstrap5Theme.h>
#include <Wt/WBorderLayout.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WMenu.h>
#include <Wt/WNavigationBar.h>
#include <Wt/WStackedWidget.h>
#include <Wt/WText.h>

using namespace std;
using namespace Wt;
using namespace yang;

Portfolio::Portfolio(const WEnvironment &env): WApplication(env){
    /*
    if(env.urlScheme() != "https"){
        redirect("https://" + env.hostName() + url());
        return;
    }
    */
    setTitle("Yang Village");
    setTheme(make_shared<WBootstrap5Theme>());
    auto borderLayout = make_unique<WBorderLayout>();

    auto navigationBar = make_unique<WNavigationBar>();
    navigationBar->setTitle("Yang Village", "https://localhost");
    navigationBar->setResponsive(true);
    navigationBar->setStyleClass("navbar-light bg-light");

    auto contentsStack = make_unique<WStackedWidget>();
    contentsStack->setStyleClass("contents");

    auto menu = make_unique<WMenu>(contentsStack.get());
    borderLayout->addWidget(move(contentsStack), LayoutPosition::Center);
    menu->setStyleClass("me-auto");
    menu->addItem("Home", make_unique<WText>("Hello World"));
    navigationBar->addMenu(move(menu));

    borderLayout->addWidget(move(navigationBar), LayoutPosition::North);
    root()->setLayout(move(borderLayout));
}
