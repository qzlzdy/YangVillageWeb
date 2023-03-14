#ifndef PORTFOLIO_ABOUT_H
#define PORTFOLIO_ABOUT_H

#include <Wt/WText.h>
#include "Section.h"

namespace yang{

class About: public Section{
public:
    About();
private:
    Wt::WText *addChevron(Wt::WContainerWidget *container);
    Wt::WText *addLabel(Wt::WContainerWidget *container,
                        const Wt::WString &text);
    Wt::WText *addPlain(Wt::WContainerWidget *container,
                        const Wt::WString &text);
};

} // namespace yang

#endif // PORTFOLIO_ABOUT_H
