#include "About.h"

#include <Wt/WBreak.h>
#include <Wt/WColor.h>
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WFont.h>
#include <Wt/WGridLayout.h>
#include <Wt/WImage.h>
#include <Wt/WText.h>

using namespace std;
using namespace Wt;
using namespace yang;

namespace {

const WString INDENT = "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;";

const WString ABOUT_DESC =
"没有什么是泰勒公式洛必达法则华里士公式伽玛函数拉格朗日乘数法牛顿莱布尼茨公式格"
"林公式斯托克斯公式高斯公式不能解决的。如若有，那超纲了。";

const WString QUAL_DESC =
"能根据软件开发项目管理和软件工程的要求，按照系统总体设计规格说明书进行软件设计"
"，编写程序设计规格说明书等相应的文档；组织和指导程序员编写、调试程序，并对软件"
"进行优化和集成测试，开发出符合系统总体设计要求的高质量软件；具有工程师的实际工"
"作能力和业务水平。";

}

About::About(){
    addSectionTitle("简介", INDENT + ABOUT_DESC);
    WContainerWidget *container = addWidget(make_unique<WContainerWidget>());
    container->setStyleClass("row");

    WImage *avatar = container->addWidget(make_unique<WImage>(
        "/images/avatar.png", "头像"));
    avatar->setStyleClass("col-lg-4 img-fluid my-auto");
    WContainerWidget *content =
        container->addWidget(make_unique<WContainerWidget>());
    content->setStyleClass("col-lg-8 pt-4 pt-lg-0");

    WText *h3 = content->addWidget(make_unique<WText>(
        "软件设计师 &amp; C++后端工程师"));
    WFont font;
    font.setWeight(FontWeight::Bold);
    font.setSize(26);
    h3->decorationStyle().setFont(font);
    h3->decorationStyle().setForegroundColor(WColor(0x17, 0x3b, 0x6c));

    content->addWidget(make_unique<WBreak>());
    WText *p = content->addWidget(make_unique<WText>(INDENT + QUAL_DESC));
    font = WFont();
    font.setStyle(FontStyle::Italic);
    p->decorationStyle().setFont(font);
    p->setMargin(0, Side::Bottom);
    p->setStyleClass("fs-4");

    content->addWidget(make_unique<WBreak>());
    WContainerWidget *details =
        content->addWidget(make_unique<WContainerWidget>());
    details->setStyleClass("p-0");
    WGridLayout *grid = details->setLayout(make_unique<WGridLayout>());
    auto addGridCell = [=](int row, int column){
        WContainerWidget *cell = grid->addWidget(
            make_unique<WContainerWidget>(), row, column,
            AlignmentFlag::Left | AlignmentFlag::Middle);
        cell->setMargin(20, Side::Bottom);
        cell->setStyleClass("d-flex align-items-center");
        return cell;
    };

    WContainerWidget *birthday = addGridCell(0, 0);
    addChevron(birthday);
    addLabel(birthday, "生日：");
    addPlain(birthday, "1999-4-12");

    WContainerWidget *age = addGridCell(0, 1);
    addChevron(age);
    addLabel(age, "年龄：");
    addPlain(age, "23");

    WContainerWidget *website = addGridCell(1, 0);
    addChevron(website);
    addLabel(website, "个人网页：");
    addPlain(website, "http://47.74.46.203");

    WContainerWidget *degree = addGridCell(1, 1);
    addChevron(degree);
    addLabel(degree, "学历：");
    addPlain(degree, "硕士");

    WContainerWidget *phone = addGridCell(2, 0);
    addChevron(phone);
    addLabel(phone, "电话：");
    addPlain(phone, "19817478853");

    WContainerWidget *email = addGridCell(2, 1);
    addChevron(email);
    addLabel(email, "邮箱：");
    addPlain(email, "qzlzdy@qq.com");

    WContainerWidget *city = addGridCell(3, 0);
    addChevron(city);
    addLabel(city, "城市：");
    addPlain(city, "浙江杭州");

    WContainerWidget *job = addGridCell(3, 1);
    addChevron(job);
    addLabel(job, "职业：");
    addPlain(job, "大魔法师");

    p = content->addWidget(make_unique<WText>(INDENT + WString("月薪400读研人")));
    p->setMargin(0, Side::Bottom);
    p->setStyleClass("fs-4");
}

void About::addChevron(WContainerWidget *container){
    WText *chevron = container->addWidget(make_unique<WText>(
        "<i class=\"bi bi-chevron-right\"/>"));
    WFont font;
    font.setSize(24);
    chevron->decorationStyle().setFont(font);
    chevron->setMargin(5, Side::Right);
    chevron->decorationStyle().setForegroundColor(WColor(0x14, 0x9d, 0xdd));
    chevron->setLineHeight(0);
}

void About::addLabel(WContainerWidget *container, const WString &text){
    WText *label = container->addWidget(make_unique<WText>(text));
    label->setMargin(10, Side::Right);
    WFont font;
    font.setSize(24);
    label->decorationStyle().setFont(font);
}

void About::addPlain(WContainerWidget *container, const WString &text){
    WText *plain = container->addWidget(make_unique<WText>(text));
    WFont font;
    font.setSize(24);
    plain->decorationStyle().setFont(font);
}
