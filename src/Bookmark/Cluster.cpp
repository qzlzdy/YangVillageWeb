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
#include "Bookmark/Cluster.h"

#include <Wt/Dbo/backend/Sqlite3.h>
#include <Wt/Dbo/Session.h>
#include <Wt/Dbo/Transaction.h>
#include <Wt/WAnchor.h>
#include <Wt/WMenuItem.h>
#include <Wt/WLink.h>
#include <Wt/WTabWidget.h>
#include <Wt/WText.h>
#include <Wt/WVBoxLayout.h>
#include "Bookmark/BookmarkInfo.h"

using namespace std;
using namespace Wt;
using namespace yang;

Cluster::Cluster(const WString &title, const string &catalog){
    WTabWidget *tabW = addNew<WTabWidget>();
    unique_ptr<WContainerWidget> root = make_unique<WContainerWidget>();
    root->setStyleClass("p-2 bg-white row row-cols-1 row-cols-md-4 g-2");

    unique_ptr<Dbo::backend::Sqlite3> db = make_unique<Dbo::backend::Sqlite3>(
        "/var/lib/yangvillage/yangvillage.db");
    Dbo::Session session;
    session.setConnection(std::move(db));
    session.mapClass<BookmarkInfo>("bookmarks");
    Dbo::Transaction trans(session);
    using Urls = Dbo::collection<Dbo::ptr<BookmarkInfo>>;

    Urls urls = session.find<BookmarkInfo>()
        .where("catalog = ?")
        .bind(catalog);
    for(auto url: urls){
        root->addWidget(makeCard(url->title, url->desc, url->url));
    }

    WMenuItem *tab = tabW->addTab(std::move(root), title);
    tab->setStyleClass("pe-none fs-4");
}

unique_ptr<WContainerWidget>
Cluster::makeCard(const WString &title, const WString &desc, const string &url){
    unique_ptr<WContainerWidget> col = make_unique<WContainerWidget>();
    col->setStyleClass("col");
    WContainerWidget *card = col->addNew<WContainerWidget>();
    card->setStyleClass("card shadow");
    WContainerWidget *body = card->addNew<WContainerWidget>();
    body->setStyleClass("card-body");
    WVBoxLayout *main = body->setLayout(make_unique<WVBoxLayout>());
    WText *tt = main->addWidget(make_unique<WText>(title));
    tt->setStyleClass("card-title fs-5");
    WText *sub = main->addWidget(make_unique<WText>(desc));
    sub->setStyleClass("card-subtitle text-muted");
    WAnchor *btn = main->addWidget(make_unique<WAnchor>(WLink(url), "访问"),
                                   0, AlignmentFlag::Right);
    btn->setStyleClass("w-25 p-2 rounded-2 bg-primary text-white fs-6 "
                       "text-center text-decoration-none");
    return col;
}
