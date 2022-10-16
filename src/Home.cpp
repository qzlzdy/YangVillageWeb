#include "Home.h"

#include <Wt/WBorder.h>
#include <Wt/WColor.h>
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WFont.h>
#include <Wt/WText.h>

using namespace std;
using namespace Wt;
using namespace yang;

Home::Home(){
    setId("home");
    decorationStyle().setBackgroundImage(
        "/images/background.png", Orientation(0), Side::CenterX | Side::Top);
    setPositionScheme(PositionScheme::Relative);
    setMinimumSize(300, 1080);
    setMargin(0, AllSides);
    setStyleClass("w-100 h-100 "
        "d-flex flex-column justify-content-center align-items-center");

    WText *h1 = addWidget(make_unique<WText>("骑着轮子的羊"));
    h1->setMargin(10, Side::Bottom);
    h1->setMargin(0, Side::Top | Side::Left | Side::Right);
    WFont font;
    font.setSize(64);
    font.setWeight(FontWeight::Bold);
    h1->decorationStyle().setFont(font);
    h1->setLineHeight(56);
    h1->decorationStyle().setForegroundColor(WColor(0xff, 0xff, 0xff));

    WText *p = addWidget(make_unique<WText>("足控、妹控、萝莉控、抖M"));
    p->decorationStyle().setForegroundColor(WColor(0xff, 0xff, 0xff));
    p->setMargin(50, Side::Bottom);
    font.setSize(26);
    font.setFamily(FontFamily::SansSerif);
    p->decorationStyle().setFont(font);
    p->setStyleClass("pb-1");
    WBorder border(BorderStyle::Solid, 3, WColor(0x14, 0x9d, 0xdd));
    p->decorationStyle().setBorder(border, Side::Bottom);
}
