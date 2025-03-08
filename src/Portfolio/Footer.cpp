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
#include "Portfolio/Footer.h"

#include <Wt/WColor.h>
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WFont.h>
#include <Wt/WText.h>
#include <Wt/WVBoxLayout.h>

using namespace std;
using namespace Wt;
using namespace yang;

Footer::Footer(){
    decorationStyle().setForegroundColor(WColor(0xf4, 0xf6, 0xfd));
    WFont font;
    font.setSize(14);
    decorationStyle().setFont(font);
    setPositionScheme(PositionScheme::Fixed);
    setMargin(0, Side::Left | Side::Bottom);
    setWidth(300);
    decorationStyle().setBackgroundColor(WColor(0x04, 0x0b, 0x14));
    setStyleClass("p-3 bottom-0");
    WVBoxLayout *layout = setLayout(make_unique<WVBoxLayout>());

    WText *copyright = layout->addWidget(make_unique<WText>(
        "&copy; Copyright <strong><span>iPortfolio</span></strong>"));
    copyright->setStyleClass("text-center");

    WText *credits = layout->addWidget(make_unique<WText>(
        "Designed by <a href=\"https://bootstrapmade.com/\">BootstrapMade</a>"));
    font.setSize(13);
    credits->decorationStyle().setFont(font);
    credits->decorationStyle().setForegroundColor(WColor(0xea, 0xeb, 0xf0));
    credits->setStyleClass("pt-1 text-center");
}
