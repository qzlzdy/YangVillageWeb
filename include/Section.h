#ifndef SECTION_H
#define SECTION_H

#include <Wt/WContainerWidget.h>
#include <Wt/WString.h>

namespace yang{

class Section: public Wt::WContainerWidget{
public:
    Section();
protected:
    void addSectionTitle(const Wt::WString &title, const Wt::WString &desc);
};

}

#endif // SECTION_H
