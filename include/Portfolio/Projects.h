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
#ifndef PORTFOLIO_PROJECTS_H
#define PORTFOLIO_PROJECTS_H

#include <Wt/WHBoxLayout.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WText.h>
#include <Wt/WString.h>
#include "Section.h"

namespace yang{

class Projects: public Section{
public:
    Projects();
private:
    Wt::WText *addFilter(Wt::WHBoxLayout *container, const Wt::WString &text);
    void setActiveStyle(Wt::WText *filter);
    void setDeactiveStyle(Wt::WText *filter);
    void setDefaultStyle(Wt::WText *filter);
    void filterClicked(Wt::WText *source);
    Wt::WText *currentActive;
    Wt::WVBoxLayout *projectList;
};

} // namespace yang

#endif // PORTFOLIO_PROJECTS_H
