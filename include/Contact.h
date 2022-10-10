#ifndef CONTACT_H
#define CONTACT_H

#include <Wt/WLeafletMap.h>
#include <Wt/WText.h>
#include "Section.h"

namespace yang{

class Contact: public Section{
public:
    Contact();
private:
    Wt::WText *addIcon(Wt::WContainerWidget *container, const Wt::WString &text);
    Wt::WText *addH4(Wt::WContainerWidget *container, const Wt::WString &text);
    Wt::WText *addPara(Wt::WContainerWidget *container, const Wt::WString &text);
    static Wt::WLeafletMap::Coordinate Home;
};

}

#endif // CONTACT_H