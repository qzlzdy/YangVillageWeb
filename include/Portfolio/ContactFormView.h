#ifndef PORTFOLIO_CONTACTFORMVIEW_H
#define PORTFOLIO_CONTACTFORMVIEW_H

#include <Wt/WLineEdit.h>
#include <Wt/WTemplateFormView.h>
#include "ContactFormModel.h"

namespace yang{

class ContactFormView: public Wt::WTemplateFormView{
public:
    ContactFormView();
private:
    void process();
    template<typename T>
    T *addInput(Wt::WFormModel::Field field);
    std::shared_ptr<ContactFormModel> model;
};

template<typename T>
T *ContactFormView::addInput(Wt::WFormModel::Field field){
    std::unique_ptr<T> input = std::make_unique<T>();
    input->setHeight(44);
    setFormWidget(field, std::move(input));
    return resolve<T *>(field);
}

} // namespace yang

#endif // PORTFOLIO_CONTACTFORMVIEW_H
