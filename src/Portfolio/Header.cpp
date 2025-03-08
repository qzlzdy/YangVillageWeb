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
#include "Portfolio/Header.h"

#include <Wt/WColor.h>
#include <Wt/WCssDecorationStyle.h>
#include "Portfolio/NavigationBar.h"
#include "Portfolio/Profile.h"
#include "Portfolio/SocialLinks.h"

using namespace std;
using namespace Wt;
using namespace yang;

Header::Header(){
    setPositionScheme(PositionScheme::Fixed);
    setOffsets(0, Side::Top | Side:: Bottom | Side::Left);
    setWidth(300);
    decorationStyle().setBackgroundColor(WColor(0x04, 0x0b, 0x014));
    setStyleClass("py-0 px-3 d-flex flex-column");
    addWidget(make_unique<Profile>());
    addWidget(make_unique<SocialLinks>());
    addWidget(make_unique<NavigationBar>());
}
