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
#include "Portfolio/NavigationBar.h"

#include <functional>
#include <Wt/WAnchor.h>
#include <Wt/WColor.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WFont.h>
#include <Wt/WVBoxLayout.h>
#include "Portfolio/Home.h"

using namespace std;
using namespace Wt;
using namespace yang;

NavigationBar::NavigationBar(){
    setStyleClass("pt-4 pb-0 px-0");
    WContainerWidget *root = addWidget(make_unique<WContainerWidget>());
    WVBoxLayout *layout = root->setLayout(make_unique<WVBoxLayout>());

    WAnchor *home = layout->addWidget(make_unique<WAnchor>(
        WLink(),
        "<i class=\"bi bi-house-door\"/>主页")
    );
    home->setObjectName("home-link");
    setDefaultStyle(home, false);
    home->clicked().connect(bind(&NavigationBar::menuClicked, this, home));

    WAnchor *about = layout->addWidget(make_unique<WAnchor>(
        WLink(),
        "<i class=\"bi bi-person\"/>简介")
    );
    about->setObjectName("about-link");
    setDefaultStyle(about);
    about->clicked().connect(bind(&NavigationBar::menuClicked, this, about));

    WAnchor *resume = layout->addWidget(make_unique<WAnchor>(
        WLink(),
        "<i class=\"bi bi-file-earmark\"/>教育 &amp; 工作经历")
    );
    resume->setObjectName("resume-link");
    setDefaultStyle(resume);
    resume->clicked().connect(bind(&NavigationBar::menuClicked, this, resume));

    WAnchor *projects = layout->addWidget(make_unique<WAnchor>(
        WLink(),
        "<i class=\"bi bi-hdd-stack\"/>项目经历")
    );
    projects->setObjectName("projects-link");
    setDefaultStyle(projects);
    projects->clicked().connect(bind(&NavigationBar::menuClicked, this, projects));

    WAnchor *contact = layout->addWidget(make_unique<WAnchor>(
        WLink(),
        "<i class=\"bi bi-envelope\"/>联系方式")
    );
    contact->setObjectName("contact-link");
    setDefaultStyle(contact);
    contact->clicked().connect(bind(&NavigationBar::menuClicked, this, contact));

    currentActive = home;
}

const WString NavigationBar::defaultStyleClass =
    "d-flex text-center text-decoration-none";

void NavigationBar::setActiveStyle(WAnchor *widget){
    WFont font;
    font.setSize(24);
    widget->decorationStyle().setFont(font);
    widget->decorationStyle().setForegroundColor(WColor(0x6f, 0x71, 0x80));
    widget->setStyleClass("pe-2 " + defaultStyleClass);
}

void NavigationBar::setDeactiveStyle(WAnchor *widget){
    WFont font;
    font.setSize(20);
    widget->decorationStyle().setFont(font);
    widget->decorationStyle().setForegroundColor(WColor(0xa8, 0xa9, 0xb4));
    widget->setStyleClass("p-3 " + defaultStyleClass);
}

void NavigationBar::setDefaultStyle(WAnchor *widget, bool isDeactive){
    widget->setMargin(0, Side::Top | Side::Left | Side::Right);
    widget->setPositionScheme(PositionScheme::Relative);
    widget->setMargin(8, Side::Bottom);
    widget->decorationStyle().setCursor(Cursor::PointingHand);
    if(isDeactive){
        setDeactiveStyle(widget);
    }
    else{
        setActiveStyle(widget);
    }
}

void NavigationBar::menuClicked(WAnchor *source){
    if(currentActive == source){
        return;
    }
    setDeactiveStyle(currentActive);
    setActiveStyle(source);
    currentActive = source;
}
