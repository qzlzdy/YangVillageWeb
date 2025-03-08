/*    YangVillage Website
 *    Copyright (C) 2024  Qzlzdy
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU Affero General Public License as published
 *    by the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Affero General Public License for more details.
 *
 *    You should have received a copy of the GNU Affero General Public License
 *    along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include "Portfolio/About.h"

#include <Wt/WAnchor.h>
#include <Wt/WBreak.h>
#include <Wt/WColor.h>
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WDate.h>
#include <Wt/WFont.h>
#include <Wt/WGridLayout.h>
#include <Wt/WImage.h>

using namespace std;
using namespace Wt;
using namespace yang;

About::About(): Section("about"){
    addSectionTitle("简介");
    WContainerWidget *container = addWidget(make_unique<WContainerWidget>());
    container->setStyleClass("row");

    WImage *avatar = container->addWidget(make_unique<WImage>(
        "/images/avatar.png", "头像"));
    avatar->setStyleClass("col-lg-4 img-fluid my-auto");
    WContainerWidget *content =
        container->addWidget(make_unique<WContainerWidget>());
    content->setStyleClass("col-lg-8 pt-4 pt-lg-0");

    WText *h3 = content->addWidget(make_unique<WText>(
        "软件设计师 &amp; C++软件研发工程师"));
    WFont font;
    font.setWeight(FontWeight::Bold);
    font.setSize(26);
    h3->decorationStyle().setFont(font);
    h3->decorationStyle().setForegroundColor(WColor(0x17, 0x3b, 0x6c));

    content->addWidget(make_unique<WBreak>());
    WText *p = content->addWidget(make_unique<WText>("&nbsp;"));
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
            make_unique<WContainerWidget>(), row, column);
        cell->setMargin(20, Side::Bottom);
        cell->setStyleClass("d-flex align-items-center");
        return cell;
    };

    WContainerWidget *birthday = addGridCell(0, 0);
    addChevron(birthday);
    addLabel(birthday, "生日：");
    addPlain(birthday, "4月");

    WContainerWidget *age = addGridCell(0, 1);
    addChevron(age);
    addLabel(age, "年龄：");
    WDate today = WDate::currentServerDate();
    addPlain(age, to_string(today.year() - 1999));

    WContainerWidget *website = addGridCell(1, 0);
    addChevron(website);
    addLabel(website, "主页：");
    WLink webAddr("https://yangvillage.top");
    WAnchor *webLink = website->addWidget(
        make_unique<WAnchor>(webAddr, "yangvillage"));
    font = WFont();
    font.setSize(24);
    webLink->decorationStyle().setFont(font);
    webLink->setStyleClass("text-decoration-none");

    WContainerWidget *degree = addGridCell(1, 1);
    addChevron(degree);
    addLabel(degree, "学历：");
    addPlain(degree, "硕士");

    WContainerWidget *phone = addGridCell(2, 0);
    addChevron(phone);
    addLabel(phone, "QQ：");
    addPlain(phone, "419286376");

    WContainerWidget *email = addGridCell(2, 1);
    addChevron(email);
    addLabel(email, "邮箱：");
    addPlain(email, "qzlzdy@qq.com");

    WContainerWidget *city = addGridCell(3, 0);
    addChevron(city);
    addLabel(city, "城市：");
    addPlain(city, "江苏南京");

    WContainerWidget *job = addGridCell(3, 1);
    addChevron(job);
    addLabel(job, "职业：");
    addPlain(job, "大魔法师");

    p = content->addWidget(make_unique<WText>("&nbsp;"));
    p->setMargin(0, Side::Bottom);
    p->setStyleClass("fs-4");
}

WText *About::addChevron(WContainerWidget *container){
    WText *chevron = container->addWidget(make_unique<WText>(
        "<i class=\"bi bi-chevron-right\"/>"));
    WFont font;
    font.setSize(24);
    chevron->decorationStyle().setFont(font);
    chevron->setMargin(5, Side::Right);
    chevron->decorationStyle().setForegroundColor(WColor(0x14, 0x9d, 0xdd));
    chevron->setLineHeight(0);
    return chevron;
}

WText *About::addLabel(WContainerWidget *container, const WString &text){
    WText *label = container->addWidget(make_unique<WText>(text));
    label->setMargin(10, Side::Right);
    WFont font;
    font.setSize(24);
    label->decorationStyle().setFont(font);
    return label;
}

WText *About::addPlain(WContainerWidget *container, const WString &text){
    WText *plain = container->addWidget(make_unique<WText>(text));
    WFont font;
    font.setSize(24);
    plain->decorationStyle().setFont(font);
    return plain;
}
