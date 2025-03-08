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
#include "Portfolio/ContactFormView.h"

#include <Wt/WColor.h>
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WEmailEdit.h>
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
    addInput<Wt::WLineEdit>(ContactFormModel::NameField);
    addInput<Wt::WEmailEdit>(ContactFormModel::EmailField)
        ->emailValidator()->setMandatory(true);
    addInput<Wt::WLineEdit>(ContactFormModel::SubjectField);
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
        model->sendMail();
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
                "信息格式错误或正文字数超出限定！"
            "</p>");
        updateView(model.get());
    }
}
