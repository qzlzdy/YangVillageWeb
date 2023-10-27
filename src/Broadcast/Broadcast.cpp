#include "Broadcast/Broadcast.h"

#include <Wt/WAnchor.h>
#include <Wt/WBootstrap5Theme.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLink.h>
#include <Wt/WText.h>
#include <Wt/WVBoxLayout.h>

using namespace std;
using namespace Wt;
using namespace yang;

Broadcast::Broadcast(const WEnvironment &env): WApplication(env){
    setTheme(make_shared<WBootstrap5Theme>());
    setTitle("羊村-广播站");

    root()->decorationStyle().setBackgroundColor(WColor(0xf5, 0xf8, 0xfd));
    WContainerWidget *contents =
        root()->addWidget(make_unique<WContainerWidget>());
    contents->setStyleClass("mx-5");
    WVBoxLayout *main = contents->setLayout(make_unique<WVBoxLayout>());

    WText *title = main->addWidget(make_unique<WText>("羊村广播站"));
    title->setStyleClass("mt-5 fs-1 text-center");

    main->addWidget(make_unique<WText>(
        "广播站暂不对外开放 如过您是本村村民 请点击下方连接"));
    main->addWidget(make_unique<WAnchor>(
        WLink("https://192.168.1.200:5443"), "直达专车"));
}
