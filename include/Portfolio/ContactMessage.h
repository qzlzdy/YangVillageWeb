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
#ifndef PORTFOLIO_CONTACTMESSAGE_H
#define PORTFOLIO_CONTACTMESSAGE_H

#include <string>
#include <Wt/Dbo/Dbo.h>

namespace Dbo = Wt::Dbo;

namespace yang{

struct ContactMessage{
    template<class Action>
    void persist(Action &a);
    std::string name;
    std::string email;
    std::string subject;
    std::string message;
};

template<class Action>
void ContactMessage::persist(Action &a){
    Dbo::field(a, name, "name");
    Dbo::field(a, email, "email");
    Dbo::field(a, subject, "subject");
    Dbo::field(a, message, "message");
}

} // namespace yang

#endif // PORTFOLIO_MESSAGES_H
