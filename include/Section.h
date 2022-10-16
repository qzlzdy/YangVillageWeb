#ifndef SECTION_H
#define SECTION_H

#include <string>
#include <Wt/WContainerWidget.h>
#include <Wt/WString.h>

namespace yang{

class Section: public Wt::WContainerWidget{
public:
    Section();
    Section(const std::string &id);
protected:
    void addSectionTitle(const Wt::WString &title);
};

}

#endif // SECTION_H
