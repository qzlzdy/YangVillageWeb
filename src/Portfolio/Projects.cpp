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
#include "Portfolio/Projects.h"

#include <functional>
#include <memory>
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/Session.h>
#include <Wt/Dbo/Transaction.h>
#include <Wt/Dbo/backend/Sqlite3.h>
#include <Wt/WColor.h>
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WFont.h>
#include <Wt/WVBoxLayout.h>
#include "Portfolio/ProjectInfo.h"

using namespace std;
using namespace Wt;
using namespace yang;

Projects::Projects(): Section("projects"){
    addSectionTitle("项目经历");
    WContainerWidget *bar = addWidget(make_unique<WContainerWidget>());
    bar->setMargin(0, Side::Top);
    bar->setMargin(35, Side::Bottom);
    bar->setMargin(WLength(), Side::Left | Side::Right);
    bar->decorationStyle().setBackgroundColor(WColor(0xff, 0xff, 0xff));
    bar->setStyleClass("row col-lg-12 d-flex justify-content-center py-0 px-3 "
                       "text-center rounded-pill");
    WHBoxLayout *filters = bar->setLayout(make_unique<WHBoxLayout>());

    WText *all = addFilter(filters, "ALL");
    setActiveStyle(all);
    all->clicked().connect(bind(&Projects::filterClicked, this, all));

    WText *android = addFilter(filters, "ANDROID");
    android->clicked().connect(bind(&Projects::filterClicked, this, android));

    WText *cpp = addFilter(filters, "C/C++");
    cpp->clicked().connect(bind(&Projects::filterClicked, this, cpp));

    WText *embedded = addFilter(filters, "EMBEDDED");
    embedded->clicked().connect(bind(&Projects::filterClicked, this, embedded));

    WText *java = addFilter(filters, "JAVA");
    java->clicked().connect(bind(&Projects::filterClicked, this, java));

    WText *python = addFilter(filters, "PYTHON");
    python->clicked().connect(bind(&Projects::filterClicked, this, python));

    currentActive = nullptr;
    projectList = addWidget(make_unique<WContainerWidget>())
        ->setLayout(make_unique<WVBoxLayout>());
    filterClicked(all);
}

WText *Projects::addFilter(WHBoxLayout *container, const WString &text){
    WText *filter = container->addWidget(make_unique<WText>(text));
    setDefaultStyle(filter);
    return filter;
}

void Projects::setActiveStyle(WText *filter){
    filter->decorationStyle().setForegroundColor(WColor(0x14, 0x9d, 0xdd));
}

void Projects::setDeactiveStyle(WText *filter){
    filter->decorationStyle().setForegroundColor(WColor(0x27, 0x28, 0x29));
}

void Projects::setDefaultStyle(WText *filter){
    WFont font;
    font.setSize(14);
    font.setWeight(FontWeight::Value, 600);
    filter->decorationStyle().setFont(font);
    filter->decorationStyle().setCursor(Cursor::PointingHand);
    filter->setMargin(5, Side::Bottom);
    filter->setStyleClass("d-inline-block py-2 px-3");
    setDeactiveStyle(filter);
}

void Projects::filterClicked(WText *source){
    if(currentActive == source){
        return;
    }
    if(currentActive != nullptr){
        setDeactiveStyle(currentActive);
    }
    setActiveStyle(source);
    currentActive = source;
    while(projectList->count() > 0){
        projectList->removeItem(projectList->itemAt(0));
    }
    ProjectType activeType = ProjectType::ALL;
    if(currentActive->text() == "C/C++"){
        activeType = ProjectType::CPP;
    }
    else if(currentActive->text() == "EMBEDDED"){
        activeType = ProjectType::EMBEDDED;
    }
    else if(currentActive->text() == "JAVA"){
        activeType = ProjectType::JAVA;
    }
    else if(currentActive->text() == "ANDROID"){
        activeType = ProjectType::ANDROID;
    }
    else if(currentActive->text() == "PYTHON"){
        activeType = ProjectType::PYTHON;
    }

    unique_ptr<Dbo::backend::Sqlite3> db = make_unique<Dbo::backend::Sqlite3>(
        "/var/lib/yangvillage/yangvillage.db");
    Dbo::Session session;
    session.setConnection(std::move(db));
    session.mapClass<ProjectInfo>("projects");
    Dbo::Transaction trans(session);
    using Projs = Dbo::collection<Dbo::ptr<ProjectInfo>>;

    Projs projs;
    if(activeType == ProjectType::ALL){
        projs = session.find<ProjectInfo>().orderBy("begin DESC");
    }
    else{
        projs = session.find<ProjectInfo>()
            .where("type = ?")
            .orderBy("begin DESC")
            .bind(activeType);
    }
    for(auto proj: projs){
        projectList->addWidget(proj->toWidget());
    }
}
