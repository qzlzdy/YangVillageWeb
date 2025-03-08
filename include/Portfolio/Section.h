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
#ifndef PORTFOLIO_SECTION_H
#define PORTFOLIO_SECTION_H

#include <string>
#include <Wt/WContainerWidget.h>
#include <Wt/WString.h>

namespace yang{

class Section: public Wt::WContainerWidget{
public:
    Section();
    Section(const std::string &id);
protected:
    void addSectionTitle(const Wt::WString &title);
private:
    void initSection();
};

} // namespace yang

#endif // PORTFOLIO_SECTION_H
