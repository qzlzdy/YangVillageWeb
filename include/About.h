#ifndef ABOUT_H
#define ABOUT_H

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

}

#endif // ABOUT_H