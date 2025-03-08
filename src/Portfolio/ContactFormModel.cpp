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
#include "Portfolio/ContactFormModel.h"

#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/Exception.h>
#include <Wt/Dbo/Session.h>
#include <Wt/Dbo/Transaction.h>
#include <Wt/Dbo/backend/Sqlite3.h>
#include <Wt/WLengthValidator.h>
#include <Wt/WEmailValidator.h>
#include "Portfolio/ContactMessage.h"

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
    setValidator(SubjectField, createSubjectValidator());
    setValidator(MessageField, createMessageValidator());
}

void ContactFormModel::sendMail(){
    unique_ptr<Dbo::backend::Sqlite3> db = make_unique<Dbo::backend::Sqlite3>(
        "/var/lib/yangvillage/yangvillage.db");
    Dbo::Session session;
    session.setConnection(std::move(db));
    session.mapClass<ContactMessage>("messages");

    Dbo::Transaction trans(session);
    unique_ptr<ContactMessage> messages = make_unique<ContactMessage>();
    messages->name = valueText(NameField).toUTF8();
    messages->email = valueText(EmailField).toUTF8();
    messages->subject = valueText(SubjectField).toUTF8();
    messages->message = valueText(MessageField).toUTF8();
    session.add(std::move(messages));
}

shared_ptr<WValidator> ContactFormModel::createNameValidator(){
    shared_ptr<WLengthValidator> v = make_shared<WLengthValidator>();
    v->setMandatory(true);
    v->setMinimumLength(2);
    v->setMaximumLength(16);
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
