#ifndef MESSAGES_H
#define MESSAGES_H

#include <string>
#include <Wt/Dbo/Dbo.h>

namespace yang{

class Messages{
public:
    Messages() = default;
    template<class Action>
    void persist(Action &a);
    std::string name;
    std::string email;
    std::string subject;
    std::string message;
};

template<class Action>
void Messages::persist(Action &a){
    Wt::Dbo::field(a, name, "name", 16);
    Wt::Dbo::field(a, email, "email");
    Wt::Dbo::field(a, subject, "subject", 64);
    Wt::Dbo::field(a, message, "message", 256);
}

}

#endif // MESSAGES_H
