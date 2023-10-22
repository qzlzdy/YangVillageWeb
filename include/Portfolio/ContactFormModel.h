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
