#ifndef CONTACTFORMVIEW_H
#define CONTACTFORMVIEW_H

#include <Wt/WLineEdit.h>
#include <Wt/WTemplateFormView.h>
#include "ContactFormModel.h"

namespace yang{

class ContactFormView: public Wt::WTemplateFormView{
public:
    ContactFormView();
private:
    void process();
    Wt::WLineEdit *addInput(Wt::WFormModel::Field field);
    std::shared_ptr<ContactFormModel> model;
};

}

#endif // CONTACTFORMVIEW_H
