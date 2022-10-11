#include "ContactFormModel.h"

#include <Wt/WLengthValidator.h>
#include <Wt/WRegExpValidator.h>

using namespace std;
using namespace Wt;
using namespace yang;

const WFormModel::Field ContactFormModel::NameField = "name";
const WFormModel::Field ContactFormModel::EmailField = "email";
const WFormModel::Field ContactFormModel::SubjectField = "subject";
const WFormModel::Field ContactFormModel::MessageField = "message";

ContactFormModel::ContactFormModel(){
    addField(NameField);
    addField(EmailField);
    addField(SubjectField);
    addField(MessageField);
    setValidator(NameField, createNameValidator());
    setValidator(EmailField, createEmailValidator());
    setValidator(SubjectField, createSubjectValidator());
    setValidator(MessageField, createMessageValidator());
}

shared_ptr<WValidator> ContactFormModel::createNameValidator(){
    shared_ptr<WLengthValidator> v = make_shared<WLengthValidator>();
    v->setMandatory(true);
    v->setMinimumLength(2);
    v->setMaximumLength(16);
    return v;
}

shared_ptr<WValidator> ContactFormModel::createEmailValidator(){
    shared_ptr<WRegExpValidator> v = make_shared<WRegExpValidator>();
    v->setMandatory(true);
    v->setRegExp("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,4}");
    return v;
}

shared_ptr<WValidator> ContactFormModel::createSubjectValidator(){
    shared_ptr<WLengthValidator> v = make_shared<WLengthValidator>();
    v->setMandatory(true);
    v->setMinimumLength(4);
    v->setMaximumLength(64);
    return v;
}

shared_ptr<WValidator> ContactFormModel::createMessageValidator(){
    shared_ptr<WLengthValidator> v = make_shared<WLengthValidator>();
    v->setMandatory(true);
    v->setMinimumLength(4);
    v->setMaximumLength(256);
    return v;;
}
