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
#include "Portfolio/Section.h"

#include <Wt/WBreak.h>
#include <Wt/WColor.h>
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WFont.h>
#include <Wt/WText.h>

using namespace std;
using namespace Wt;
using namespace yang;

Section::Section(){
    initSection();
}

Section::Section(const string &id){
    setObjectName(id);
    initSection();
}

void Section::addSectionTitle(const WString &title){
    WText *h2 = addWidget(make_unique<WText>(title));
    WFont font;
    font.setSize(32);
    font.setWeight(FontWeight::Bold);
    h2->decorationStyle().setFont(font);
    h2->setMargin(20, Side::Bottom);
    h2->setPositionScheme(PositionScheme::Relative);
    h2->decorationStyle().setForegroundColor(WColor(0x17, 0x3b, 0x6c));
    h2->setStyleClass("pb-3");

    WText *line = addWidget(make_unique<WText>(""));
    line->setPositionScheme(PositionScheme::Absolute);
    line->setStyleClass("d-block");
    line->setWidth(150);
    line->setHeight(3);
    line->decorationStyle().setBackgroundColor(WColor(0x14, 0x9d, 0xdd));
    line->setMargin(0, Side::Bottom | Side::Left);

    addWidget(make_unique<WBreak>());
    WText *p = addWidget(make_unique<WText>("&nbsp;"));
    p->setMargin(0, Side::Bottom);
    p->setStyleClass("pb-4 fs-4");
}

void Section::initSection(){
    decorationStyle().setBackgroundColor(WColor(0xf5, 0xf8, 0xfd));
    setPositionScheme(PositionScheme::Relative);
    setMargin(306, Side::Left);
    setStyleClass("py-5 px-0");
}
