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
#include "Portfolio/Profile.h"

#include <Wt/WAnchor.h>
#include <Wt/WBorder.h>
#include <Wt/WColor.h>
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WFont.h>
#include <Wt/WImage.h>
#include <Wt/WLength.h>
#include <Wt/WLink.h>
#include <Wt/WVBoxLayout.h>

using namespace std;
using namespace Wt;
using namespace yang;

Profile::Profile(){
    WVBoxLayout *layout = setLayout(make_unique<WVBoxLayout>());
    layout->setSpacing(0);

    WImage *avatar = layout->addWidget(
        make_unique<WImage>("images/avatar.png", "头像"));
    avatar->setMargin(15, Side::Top | Side::Bottom);
    avatar->setMargin(WLength::Auto, Side::Left | Side::Right);
    avatar->setWidth(120);
    avatar->decorationStyle().setBorder(
        WBorder(BorderStyle::Solid, 8, WColor(0x2c, 0x2f, 0x3f)));
    avatar->setStyleClass("d-block img_fluid rounded-circle");

    WLink link(LinkType::InternalPath, "/");
    link.setTarget(LinkTarget::Self);
    WAnchor *name = layout->addWidget(make_unique<WAnchor>(link, "骑着轮子的羊"));
    name->setMargin(0, AllSides);
    WFont font(FontFamily::SansSerif);
    font.setSize(24);
    font.setWeight(FontWeight::Value, 600);
    name->decorationStyle().setFont(font);
    name->setStyleClass("p-0 text-center text-light text-decoration-none");
}
