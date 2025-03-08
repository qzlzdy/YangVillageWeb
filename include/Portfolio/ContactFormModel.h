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
#ifndef PORTFOLIO_CONTACTFORMMODEL_H
#define PORTFOLIO_CONTACTFORMMODEL_H

#include <Wt/WFormModel.h>
#include <Wt/WValidator.h>

namespace yang{

class ContactFormModel: public Wt::WFormModel{
public:
    static const Field NameField;
    static const Field EmailField;
    static const Field SubjectField;
    static const Field MessageField;
    ContactFormModel();
    void sendMail();
private:
    std::shared_ptr<Wt::WValidator> createNameValidator();
    std::shared_ptr<Wt::WValidator> createSubjectValidator();
    std::shared_ptr<Wt::WValidator> createMessageValidator();
};

} // namespace yang

#endif // PORTFOLIO_CONTACTFORMMODEL_H
