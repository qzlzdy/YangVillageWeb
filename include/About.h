#ifndef ABOUT_H
#define ABOUT_H

#include <Wt/WString.h>
#include <Wt/WWebWidget.h>

#include "Section.h"

namespace yang{

class About: public Section{
public:
    About();
private:
    void addChevron(Wt::WContainerWidget *container);
    void addLabel(Wt::WContainerWidget *container, const Wt::WString &text);
    void addPlain(Wt::WContainerWidget *container, const Wt::WString &text);
};

}

#endif // ABOUT_H