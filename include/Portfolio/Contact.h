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
#ifndef PORTFOLIO_CONTACT_H
#define PORTFOLIO_CONTACT_H

#include <Wt/WLeafletMap.h>
#include <Wt/WText.h>
#include "Section.h"

namespace yang{

class Contact: public Section{
public:
    Contact();
private:
    static Wt::WLeafletMap::Coordinate Home;
    Wt::WText *addIcon(Wt::WContainerWidget *container, const Wt::WString &text);
    Wt::WText *addH4(Wt::WContainerWidget *container, const Wt::WString &text);
    Wt::WText *addPara(Wt::WContainerWidget *container, const Wt::WString &text);
};

} // namespace yang

#endif // PORTFOLIO_CONTACT_H
