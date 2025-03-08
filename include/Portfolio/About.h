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
#ifndef PORTFOLIO_ABOUT_H
#define PORTFOLIO_ABOUT_H

#include <Wt/WText.h>
#include "Section.h"

namespace yang{

class About: public Section{
public:
    About();
private:
    Wt::WText *addChevron(Wt::WContainerWidget *container);
    Wt::WText *addLabel(Wt::WContainerWidget *container,
                        const Wt::WString &text);
    Wt::WText *addPlain(Wt::WContainerWidget *container,
                        const Wt::WString &text);
};

} // namespace yang

#endif // PORTFOLIO_ABOUT_H
