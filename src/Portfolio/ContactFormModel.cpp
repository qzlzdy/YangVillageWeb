#include "Portfolio/ContactFormModel.h"

#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/Exception.h>
#include <Wt/Dbo/Session.h>
#include <Wt/Dbo/Transaction.h>
#include <Wt/Dbo/backend/Sqlite3.h>
#include <Wt/WLengthValidator.h>
#include <Wt/WRegExpValidator.h>
#include <Portfolio/Messages.h>

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

void ContactFormModel::sendMail(){
    unique_ptr<Dbo::backend::Sqlite3> db =
        make_unique<Dbo::backend::Sqlite3>("yangvillage.db");
    Dbo::Session session;
    session.setConnection(move(db));
    session.mapClass<Messages>("messages");
    try{
        session.createTables();
    }
    catch(Dbo::Exception &e){
        static_cast<void>(e);
    }
    Dbo::Transaction trans(session);
    unique_ptr<Messages> messages = make_unique<Messages>();
    messages->name = valueText(NameField).toUTF8();
    messages->email = valueText(EmailField).toUTF8();
    messages->subject = valueText(SubjectField).toUTF8();
    messages->message = valueText(MessageField).toUTF8();
    session.add(move(messages));
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
