#include "ContactFormView.h"

#include <Wt/WColor.h>
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WFont.h>
#include <Wt/WPushButton.h>
#include <Wt/WTextEdit.h>

using namespace std;
using namespace Wt;
using namespace yang;

ContactFormView::ContactFormView(){
    model = make_shared<ContactFormModel>();
    setTemplateText(tr("contactForm-template"));
    addFunction("id", &WTemplate::Functions::id);

    bindString("title", "联系我");
    addInput(ContactFormModel::NameField);
    addInput(ContactFormModel::EmailField);
    addInput(ContactFormModel::SubjectField);
    unique_ptr<WTextEdit> tinymce = make_unique<WTextEdit>();
    tinymce->setMinimumSize(WLength(), 300);
    WFont font;
    font.setSize(14);
    tinymce->decorationStyle().setFont(font);
    tinymce->setStyleClass("shadow-none py-3 px-4");
    setFormWidget(ContactFormModel::MessageField, move(tinymce));

    WPushButton *submit = bindWidget("submit", make_unique<WPushButton>("提交"));
    submit->decorationStyle().setBackgroundColor(WColor(0x14, 0x9d, 0xdd));
    submit->decorationStyle().setForegroundColor(WColor(0xff, 0xff, 0xff));
    submit->clicked().connect(this, &ContactFormView::process);
    bindEmpty("submit-info");

    updateView(model.get());
}

void ContactFormView::process(){
    updateModel(model.get());
    if(model->validate()){
        bindString("submit-info",
            "<p class=\"alert alert-success\">"
                "提交成功！"
            "</p>");
        updateView(model.get());
        WTextEdit *viewField = resolve<WTextEdit *>(ContactFormModel::MessageField);
        viewField->setFocus(true);
    }
    else{
        bindString("submit-info",
            "<p class=\"alert alert-danger\">"
                "信息格式错误或正文过短！"
            "</p>");
        updateView(model.get());
    }
}

WLineEdit *ContactFormView::addInput(WFormModel::Field field){
    unique_ptr<WLineEdit> input = make_unique<WLineEdit>();
    input->setHeight(44);
    setFormWidget(field, move(input));
    return resolve<WLineEdit *>(field);
}
