#include "Bookmark/Bookmark.h"

#include <string>
#include <Wt/WBootstrap5Theme.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WText.h>
#include "Bookmark/Cluster.h"

using namespace std;
using namespace Wt;
using namespace yang;

Bookmark::Bookmark(const WEnvironment &env): WApplication(env){
    if(env.urlScheme() != "https"){
        string fullUrl = url();
        string cleanUrl = fullUrl.substr(0, fullUrl.find_first_of('?'));
        redirect("https://" + env.hostName() + cleanUrl);
        return;
    }
    setTheme(make_shared<WBootstrap5Theme>());
    setTitle("羊村-客运中心");

    root()->decorationStyle().setBackgroundColor(WColor(0xf5, 0xf8, 0xfd));
    WContainerWidget *contents =
        root()->addWidget(make_unique<WContainerWidget>());
    contents->setStyleClass("mx-5");
    WVBoxLayout *main = contents->setLayout(make_unique<WVBoxLayout>());

    WText *title = main->addWidget(make_unique<WText>("羊村客运中心"));
    title->setStyleClass("mt-5 fs-1 text-center");

    main->addWidget(make_unique<Cluster>("编程文档", "ref"));
    main->addWidget(make_unique<Cluster>("百科全书", "wiki"));
    main->addWidget(make_unique<Cluster>("追番", "anime"));
    main->addWidget(make_unique<Cluster>("游戏", "game"));
    main->addWidget(make_unique<Cluster>("小工具", "tool"));
    main->addWidget(make_unique<Cluster>("社区", "comm"));
    main->addWidget(make_unique<Cluster>("解析、例子、文章", "artc"));
}
