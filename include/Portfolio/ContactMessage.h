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
