#include "NavigationBar.h"

#include <Wt/WAnchor.h>
#include <Wt/WColor.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WFont.h>
#include <Wt/WVBoxLayout.h>
#include "Home.h"

using namespace std;
using namespace Wt;
using namespace yang;

NavigationBar::NavigationBar(){
    setStyleClass("pt-4 pb-0 px-0");
    WContainerWidget *root = addWidget(make_unique<WContainerWidget>());
    WVBoxLayout *layout = root->setLayout(make_unique<WVBoxLayout>());

    WAnchor *home = layout->addWidget(make_unique<WAnchor>(WLink(),
        "<i class=\"bi bi-house-door\"/>主页"));
    setDefaultStyle(home, false);

    WAnchor *about = layout->addWidget(make_unique<WAnchor>(WLink(),
        "<i class=\"bi bi-person\"/>简介"));
    setDefaultStyle(about);

    WAnchor *resume = layout->addWidget(make_unique<WAnchor>(WLink(),
        "<i class=\"bi bi-file-earmark\"/>教育 &amp; 工作经历"));
    setDefaultStyle(resume);

    WAnchor *portfolio = layout->addWidget(make_unique<WAnchor>(WLink(),
        "<i class=\"bi bi-hdd-stack\"/>项目经历"));
    setDefaultStyle(portfolio);

    WAnchor *contact = layout->addWidget(make_unique<WAnchor>(WLink(),
        "<i class=\"bi bi-envelope\"/>联系方式"));
    setDefaultStyle(contact);
}

const WString NavigationBar::defaultStyleClass =
    "d-flex text-center text-decoration-none";

void NavigationBar::setActiveStyle(WWebWidget *widget){
    WFont font;
    font.setSize(24);
    widget->decorationStyle().setFont(font);
    widget->decorationStyle().setForegroundColor(WColor(0x6f, 0x71, 0x80));
    widget->setStyleClass("pe-2 " + defaultStyleClass);
}

void NavigationBar::setDeactiveStyle(WWebWidget *widget){
    WFont font;
    font.setSize(20);
    widget->decorationStyle().setFont(font);
    widget->decorationStyle().setForegroundColor(WColor(0xa8, 0xa9, 0xb4));
    widget->setStyleClass("p-3 " + defaultStyleClass);
}

void NavigationBar::setDefaultStyle(WWebWidget *widget, bool isDeactive){
    widget->setMargin(0, Side::Top | Side::Left | Side::Right);
    widget->setPositionScheme(PositionScheme::Relative);
    widget->setMargin(8, Side::Bottom);
    if(isDeactive){
        setDeactiveStyle(widget);
    }
    else{
        setActiveStyle(widget);
    }
}
