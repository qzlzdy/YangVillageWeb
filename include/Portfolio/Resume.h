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
#ifndef PORTFOLIO_RESUME_H
#define PORTFOLIO_RESUME_H

#include <Wt/WText.h>
#include <Wt/WVBoxLayout.h>
#include "Section.h"

namespace yang{

class Resume: public Section{
public:
    Resume();
private:
    Wt::WText *addTitle(Wt::WVBoxLayout *layout, const Wt::WString &text);
    Wt::WContainerWidget *addItem(Wt::WVBoxLayout *layout);
    void setH4Style(Wt::WText *h4);
    Wt::WText *addH4(Wt::WContainerWidget *container, const Wt::WString &text);
    Wt::WText *addH4(Wt::WVBoxLayout *container, const Wt::WString &text);
    Wt::WText *addH5(Wt::WVBoxLayout *container, const Wt::WString &text);
    Wt::WVBoxLayout *addUl(Wt::WContainerWidget *container);
    Wt::WText *addLi(Wt::WVBoxLayout *ul, const Wt::WString &text);
};

} // namespace yang

#endif // PORTFOLIO_RESUME_H
