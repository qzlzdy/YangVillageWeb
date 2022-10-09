#include "Resume.h"

#include <Wt/WBorder.h>
#include <Wt/WBreak.h>
#include <Wt/WColor.h>
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WFont.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WText.h>

using namespace std;
using namespace Wt;
using namespace yang;

Resume::Resume(){
    addSectionTitle("教育 &amp; 工作经历");
    WContainerWidget *content = addWidget(make_unique<WContainerWidget>());
    WHBoxLayout *row = content->setLayout(make_unique<WHBoxLayout>());
    WContainerWidget *left = row->addWidget(make_unique<WContainerWidget>());
    WVBoxLayout *leftCol = left->setLayout(make_unique<WVBoxLayout>());
    WContainerWidget *right = row->addWidget(make_unique<WContainerWidget>());
    WVBoxLayout *rightCol = right->setLayout(make_unique<WVBoxLayout>());

    addTitle(leftCol, "总览");
    WContainerWidget *summary = addItem(leftCol);
    addH4(summary, "骑着轮子的羊");
    summary->addWidget(make_unique<WBreak>());
    WText *p = summary->addWidget(make_unique<WText>("&nbsp;"));
    WFont font;
    font.setWeight(FontWeight::Bold);
    p->decorationStyle().setFont(font);
    WVBoxLayout *summaryUl = addUl(summary);
    addLi(summaryUl, "浙江省嘉兴市平湖市");
    addLi(summaryUl, "314200");
    addLi(summaryUl, "qzlzdy@qq.com");

    addTitle(leftCol, "教育");
    WVBoxLayout *master =
        addItem(leftCol)->setLayout(make_unique<WVBoxLayout>());
    addH4(master, "工学硕士");
    addH5(master, "2021 - 2024");
    p = master->addWidget(make_unique<WText>(
        "杭州电子科技大学" "&nbsp;&nbsp;&nbsp;&nbsp;"
        "计算机学院" "&nbsp;&nbsp;&nbsp;&nbsp;"
        "计算机科学与技术"));
    p->decorationStyle().setFont(font);

    WVBoxLayout *bachelor =
        addItem(leftCol)->setLayout(make_unique<WVBoxLayout>());
    addH4(bachelor, "工学学士");
    addH5(bachelor, "2017 - 2021");
    p = bachelor->addWidget(make_unique<WText>(
        "杭州电子科技大学" "&nbsp;&nbsp;&nbsp;&nbsp;"
        "计算机学院" "&nbsp;&nbsp;&nbsp;&nbsp;"
        "计算机科学与技术"));
    p->decorationStyle().setFont(font);

    addTitle(rightCol, "工作经历");
    WVBoxLayout *expr =
        addItem(rightCol)->setLayout(make_unique<WVBoxLayout>());
    addH4(expr, "浙江智臾科技有限公司");
    addH5(expr, "2021.2 - 2021.6");
    p = expr->addWidget(make_unique<WText>("C++后端开发实习"));
    p->decorationStyle().setFont(font);
}

WText *Resume::addTitle(WVBoxLayout *layout, const WString &text){
    WText *title = layout->addWidget(make_unique<WText>(text));
    WFont font;
    font.setSize(26);
    font.setWeight(FontWeight::Bold);
    title->decorationStyle().setFont(font);
    title->setMargin(20, Side::Top | Side::Bottom);
    title->decorationStyle().setForegroundColor(WColor(0x05, 0x0d, 0x18));
    return title;
}

WContainerWidget *Resume::addItem(WVBoxLayout *layout){
    WContainerWidget *item = layout->addWidget(make_unique<WContainerWidget>());
    item->setMargin(-2, Side::Top);
    WBorder border(BorderStyle::Solid, 2, WColor(0x1f, 0x52, 0x97));
    item->decorationStyle().setBorder(border, Side::Left);
    item->setPositionScheme(PositionScheme::Relative);
    item->setStyleClass("pt-0 pe-0 pb-3 ps-3");
    return item;
}

void Resume::setH4Style(WText *h4){
    h4->setLineHeight(18);
    WFont font;
    font.setSize(18);
    font.setWeight(FontWeight::Value, 600);
    font.setFamily(FontFamily::SansSerif);
    h4->decorationStyle().setFont(font);
    h4->decorationStyle().setForegroundColor(WColor(0x05, 0x0d, 0x18));
    h4->setMargin(10, Side::Bottom);
    h4->setStyleClass("");
}

WText *Resume::addH4(WContainerWidget *container, const WString &text){
    WText *h4 = container->addWidget(make_unique<WText>(text));
    setH4Style(h4);
    return h4;
}

WText *Resume::addH4(WVBoxLayout *container, const WString &text){
    WText *h4 = container->addWidget(make_unique<WText>(text));
    setH4Style(h4);
    return h4;
}

WText *Resume::addH5(WVBoxLayout *container, const WString &text){
    WText *h5 = container->addWidget(make_unique<WText>(text));
    WFont font;
    font.setSize(16);
    font.setWeight(FontWeight::Value, 600);
    h5->decorationStyle().setFont(font);
    h5->decorationStyle().setBackgroundColor(WColor(0xe4, 0xed, 0xf9));
    h5->setMargin(10, Side::Bottom);
    h5->setStyleClass("d-inline-block py-1 px-3");
    return h5;
}

WVBoxLayout *Resume::addUl(WContainerWidget *container){
    WContainerWidget *ul =
        container->addWidget(make_unique<WContainerWidget>());
    ul->setStyleClass("ps-4");
    return ul->setLayout(make_unique<WVBoxLayout>());
}

WText *Resume::addLi(WVBoxLayout *ul, const WString &text){
    WText *li = ul->addWidget(make_unique<WText>(text));
    li->setStyleClass("pb-3");
    return li;
}
