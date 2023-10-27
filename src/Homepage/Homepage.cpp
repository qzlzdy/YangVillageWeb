#include "Homepage/Homepage.h"

#include <string>
#include <Wt/WAnchor.h>
#include <Wt/WBootstrap5Theme.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLink.h>
#include <Wt/WText.h>
#include <Wt/WVBoxLayout.h>

using namespace std;
using namespace Wt;
using namespace yang;

Homepage::Homepage(const WEnvironment &env): WApplication(env){
    setTheme(make_shared<WBootstrap5Theme>());
    setTitle("羊村");

    root()->decorationStyle().setBackgroundColor(WColor(0xf5, 0xf8, 0xfd));
    WContainerWidget *contents =
        root()->addWidget(make_unique<WContainerWidget>());
    contents->setStyleClass("mx-5");
    WVBoxLayout *main = contents->setLayout(make_unique<WVBoxLayout>());

    WText *title = main->addWidget(make_unique<WText>("羊村"));
    title->setStyleClass("mt-5 fs-1 text-center");

    main->addWidget(make_unique<WAnchor>(
        WLink("https://bookmark.yangvillage.top"), "羊村客运中心"));
    main->addWidget(make_unique<WAnchor>(
        WLink("https://music.yangvillage.top"), "羊村广播站"));
    main->addWidget(make_unique<WAnchor>(
        WLink("https://author.yangvillage.top"), "羊村村长室(个人主页)"));
}
