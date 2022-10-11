#ifndef CONTACTFORMMODEL_H
#define CONTACTFORMMODEL_H

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
private:
    std::shared_ptr<Wt::WValidator> createNameValidator();
    std::shared_ptr<Wt::WValidator> createEmailValidator();
    std::shared_ptr<Wt::WValidator> createSubjectValidator();
    std::shared_ptr<Wt::WValidator> createMessageValidator();
};

}

#endif // CONTACTFORMMODEL_H
