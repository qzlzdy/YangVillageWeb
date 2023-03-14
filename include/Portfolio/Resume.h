#ifndef PORTFOLIO_RESUME_H
#define PORTFOLIO_RESUME_H

#include <Wt/WText.h>
#include <Wt/WVBoxLayout.h>
#include "Section.h"

namespace yang{

class Resume: public Section{
public:
    Resume();
private:
    Wt::WText *addTitle(Wt::WVBoxLayout *layout, const Wt::WString &text);
    Wt::WContainerWidget *addItem(Wt::WVBoxLayout *layout);
    void setH4Style(Wt::WText *h4);
    Wt::WText *addH4(Wt::WContainerWidget *container, const Wt::WString &text);
    Wt::WText *addH4(Wt::WVBoxLayout *container, const Wt::WString &text);
    Wt::WText *addH5(Wt::WVBoxLayout *container, const Wt::WString &text);
    Wt::WVBoxLayout *addUl(Wt::WContainerWidget *container);
    Wt::WText *addLi(Wt::WVBoxLayout *ul, const Wt::WString &text);
};

} // namespace yang

#endif // PORTFOLIO_RESUME_H
