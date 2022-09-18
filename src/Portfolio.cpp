#include "Portfolio.h"

#include <Wt/WBootstrap5Theme.h>
#include <Wt/WBorderLayout.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WMenu.h>
#include <Wt/WNavigationBar.h>
#include <Wt/WStackedWidget.h>
#include <Wt/WText.h>
#include "HomePage.h"

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
    setTitle("羊村");
    setTheme(make_shared<WBootstrap5Theme>());
    WBorderLayout *borderLayout = root()->setLayout(
        make_unique<WBorderLayout>());

    WNavigationBar *navigationBar = borderLayout->addWidget(
        make_unique<WNavigationBar>(), LayoutPosition::North);
    navigationBar->setTitle("羊村", "http://47.74.46.203");
    navigationBar->setResponsive(true);
    navigationBar->setStyleClass("navbar-light bg-light");

    WStackedWidget *contentsStack = borderLayout->addWidget(
        make_unique<WStackedWidget>(), LayoutPosition::Center);
    contentsStack->setStyleClass("contents");

    WMenu *menu = navigationBar->addMenu(make_unique<WMenu>(contentsStack));
    menu->setStyleClass("me-auto");
    menu->addItem("主页", make_unique<HomePage>());
}
