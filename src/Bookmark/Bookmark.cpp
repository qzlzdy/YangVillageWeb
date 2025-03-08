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
#include "Bookmark/Bookmark.h"

#include <string>
#include <Wt/WBootstrap5Theme.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WText.h>
#include "Bookmark/Cluster.h"

using namespace std;
using namespace Wt;
using namespace yang;

Bookmark::Bookmark(const WEnvironment &env): WApplication(env){
    setTheme(make_shared<WBootstrap5Theme>());
    setTitle("羊村-客运中心");

    root()->decorationStyle().setBackgroundColor(WColor(0xf5, 0xf8, 0xfd));
    WContainerWidget *contents =
        root()->addWidget(make_unique<WContainerWidget>());
    contents->setStyleClass("mx-5");
    WVBoxLayout *main = contents->setLayout(make_unique<WVBoxLayout>());

    WText *title = main->addWidget(make_unique<WText>("羊村客运中心"));
    title->setStyleClass("mt-5 fs-1 text-center");

    main->addWidget(make_unique<Cluster>("编程文档", "ref"));
    main->addWidget(make_unique<Cluster>("百科全书", "wiki"));
    main->addWidget(make_unique<Cluster>("追番追漫", "anime"));
    main->addWidget(make_unique<Cluster>("游戏", "game"));
    main->addWidget(make_unique<Cluster>("小工具", "tool"));
    main->addWidget(make_unique<Cluster>("社区", "comm"));
    main->addWidget(make_unique<Cluster>("解析、例子、文章", "artc"));
    main->addWidget(make_unique<Cluster>("Ypologist专区", "ypo"));
}
