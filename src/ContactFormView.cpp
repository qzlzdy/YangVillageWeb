#include "ContactFormView.h"

#include <Wt/WPushButton.h>
#include <Wt/WLineEdit.h>
#include <Wt/WTextEdit.h>

using namespace std;
using namespace Wt;
using namespace yang;

ContactFormView::ContactFormView(){
    model = make_shared<ContactFormModel>();
    setTemplateText(tr("contactForm-template"));
    addFunction("id", &WTemplate::Functions::id);
    setFormWidget(ContactFormModel::NameField, make_unique<WLineEdit>());
    setFormWidget(ContactFormModel::EmailField, make_unique<WLineEdit>());
    setFormWidget(ContactFormModel::SubjectField, make_unique<WLineEdit>());
    setFormWidget(ContactFormModel::MessageField, make_unique<WTextEdit>());
    WPushButton *submit = bindWidget("submit", make_unique<WPushButton>());
    submit->clicked().connect(this, &ContactFormView::process);
    updateView(model.get());
}

void ContactFormView::process(){
    updateModel(model.get());
    if(model->validate()){
        bindString("submit-info", "Send successful!", TextFormat::Plain);
        updateView(model.get());
        WLineEdit *viewField = resolve<WLineEdit *>(ContactFormModel::NameField);
        viewField->setFocus(true);
    }
    else{
        bindEmpty("submit-info");
        updateView(model.get());
    }
}
