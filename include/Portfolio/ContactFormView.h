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
#ifndef PORTFOLIO_CONTACTFORMVIEW_H
#define PORTFOLIO_CONTACTFORMVIEW_H

#include <Wt/WLineEdit.h>
#include <Wt/WTemplateFormView.h>
#include "ContactFormModel.h"

namespace yang{

class ContactFormView: public Wt::WTemplateFormView{
public:
    ContactFormView();
private:
    void process();
    template<typename T>
    T *addInput(Wt::WFormModel::Field field);
    std::shared_ptr<ContactFormModel> model;
};

template<typename T>
T *ContactFormView::addInput(Wt::WFormModel::Field field){
    std::unique_ptr<T> input = std::make_unique<T>();
    input->setHeight(44);
    setFormWidget(field, std::move(input));
    return resolve<T *>(field);
}

} // namespace yang

#endif // PORTFOLIO_CONTACTFORMVIEW_H
