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
#ifndef PORTFOLIO_NAVIGATIONBAR_H
#define PORTFOLIO_NAVIGATIONBAR_H

#include <Wt/WAnchor.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WNavigationBar.h>
#include <Wt/WString.h>

namespace yang{

class NavigationBar: public Wt::WNavigationBar{
public:
    NavigationBar();
private:
    static const Wt::WString defaultStyleClass;
    void setActiveStyle(Wt::WAnchor *widget);
    void setDeactiveStyle(Wt::WAnchor *widget);
    void setDefaultStyle(Wt::WAnchor *widget, bool isDeactive = true);
    void menuClicked(Wt::WAnchor *source);
    Wt::WAnchor *currentActive;
};

} // namespace yang

#endif // PORTFOLIO_NAVIGATIONBAR_H
