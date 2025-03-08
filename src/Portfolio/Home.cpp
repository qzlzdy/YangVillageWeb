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
#include "Portfolio/Home.h"

#include <Wt/WBorder.h>
#include <Wt/WColor.h>
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WFont.h>
#include <Wt/WText.h>

using namespace std;
using namespace Wt;
using namespace yang;

Home::Home(){
    setObjectName("home");
    decorationStyle().setBackgroundImage(
        "/images/background.png", Orientation(0), Side::CenterX | Side::Top);
    setPositionScheme(PositionScheme::Relative);
    setMinimumSize(300, 1080);
    setMargin(0, AllSides);
    setStyleClass("w-100 h-100 d-flex flex-column justify-content-center "
                  "align-items-center");

    WText *h1 = addWidget(make_unique<WText>("骑着轮子的羊"));
    h1->setMargin(10, Side::Bottom);
    h1->setMargin(0, Side::Top | Side::Left | Side::Right);
    WFont font;
    font.setSize(64);
    font.setWeight(FontWeight::Bold);
    h1->decorationStyle().setFont(font);
    h1->setLineHeight(56);
    h1->decorationStyle().setForegroundColor(WColor(0xff, 0xff, 0xff));

    WText *p = addWidget(make_unique<WText>("足フェチ、臭いフェチ、サイズフェチ、マゾ"));
    p->decorationStyle().setForegroundColor(WColor(0xff, 0xff, 0xff));
    p->setMargin(50, Side::Bottom);
    font.setSize(26);
    font.setFamily(FontFamily::SansSerif);
    p->decorationStyle().setFont(font);
    p->setStyleClass("pb-1");
    WBorder border(BorderStyle::Solid, 3, WColor(0x14, 0x9d, 0xdd));
    p->decorationStyle().setBorder(border, Side::Bottom);
}
