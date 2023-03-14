#include "Portfolio/Contact.h"

#include <Wt/WBreak.h>
#include <Wt/WColor.h>
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WFont.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WVBoxLayout.h>
#include "Portfolio/ContactFormView.h"

using namespace std;
using namespace Wt;
using namespace yang;

Contact::Contact(): Section("contact"){
    setStyleClass("pb-5");
    addSectionTitle("联系方式");
    WHBoxLayout *row = addWidget(make_unique<WContainerWidget>())
        ->setLayout(make_unique<WHBoxLayout>());
    WContainerWidget *left = row->addWidget(make_unique<WContainerWidget>());
    WVBoxLayout *leftCol = left->setLayout(make_unique<WVBoxLayout>());
    WContainerWidget *right = row->addWidget(make_unique<WContainerWidget>());
    WVBoxLayout *rightCol = right->setLayout(make_unique<WVBoxLayout>());

    left->decorationStyle().setBackgroundColor(WColor(0xff, 0xff, 0xff));
    left->setStyleClass("d-flex align-items-stretch p-5 shadow");

    WContainerWidget *address = leftCol->addWidget(make_unique<WContainerWidget>());
    addIcon(address, "<i class=\"bi bi-geo-alt\"/>");
    addH4(address, "地点：");
    address->addWidget(make_unique<WBreak>());
    addPara(address, "浙江省杭州市钱塘区杭州电子科技大学");

    WContainerWidget *email = leftCol->addWidget(make_unique<WContainerWidget>());
    addIcon(email, "<i class=\"bi bi-envelope\"/>");
    addH4(email, "邮箱：");
    email->addWidget(make_unique<WBreak>());
    addPara(email, "qzlzdy@qq.com");

    WContainerWidget *qq = leftCol->addWidget(make_unique<WContainerWidget>());
    addIcon(qq, "<i class=\"bi bi-quora\"/>");
    addH4(qq, "QQ：");
    qq->addWidget(make_unique<WBreak>());
    addPara(qq, "419286376");

    WLeafletMap *map = leftCol->addWidget(make_unique<WLeafletMap>());
    map->resize(430, 290);
    Json::Object options;
    options["attribution"] =
        "&copy; <a href=\"https://www.openstreetmap.org/copyright\">"
            "OpenStreetMap"
        "</a> contributors";
    map->addTileLayer("https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png", options);
    map->panTo(Home);
    map->addMarker(make_unique<WLeafletMap::LeafletMarker>(Home));
    map->setZoomLevel(16);

    right->setMargin(5, Side::Top);
    right->setStyleClass("d-flex align-items-stretch");

    ContactFormView *form = rightCol->addWidget(make_unique<ContactFormView>());
    form->decorationStyle().setBackgroundColor(WColor(0xff, 0xff, 0xff));
    form->setStyleClass("w-100 p-4 shadow");

    row->setStretchFactor(left, 5);
    row->setStretchFactor(right, 7);
}

WLeafletMap::Coordinate Contact::Home(30.318400, 120.337750);

WText *Contact::addIcon(WContainerWidget *container, const WString &text){
    WText *icon = container->addWidget(make_unique<WText>(text));
    WFont font;
    font.setSize(20);
    icon->decorationStyle().setFont(font);
    icon->decorationStyle().setForegroundColor(WColor(0x14, 0x9d, 0xdd));
    icon->setWidth(44);
    icon->setHeight(44);
    icon->decorationStyle().setBackgroundColor(WColor(0xdf, 0xf3, 0xfc));
    icon->setStyleClass(
        "justify-content-center align-items-center "
        "d-flex rounded-circle float-start");
    return icon;
}

WText *Contact::addH4(WContainerWidget *container, const WString &text){
    WText *h4 = container->addWidget(make_unique<WText>(text));
    WFont font;
    font.setSize(22);
    font.setWeight(FontWeight::Value, 600);
    h4->decorationStyle().setFont(font);
    h4->setMargin(5, Side::Bottom);
    h4->decorationStyle().setForegroundColor(WColor(0x05, 0x0d, 0x18));
    h4->setStyleClass("py-0 ps-5 pe-0");
    return h4;
}

WText *Contact::addPara(WContainerWidget *container, const WString &text){
    WText *p = container->addWidget(make_unique<WText>(text));
    p->setMargin(20, Side::Bottom);
    WFont font;
    font.setSize(14);
    p->decorationStyle().setFont(font);
    p->decorationStyle().setForegroundColor(WColor(0x17, 0x3b, 0x6c));
    p->setStyleClass("pt-0 pe-0 pb-2 ps-5");
    return p;
}
