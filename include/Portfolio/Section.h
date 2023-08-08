#ifndef PORTFOLIO_SECTION_H
#define PORTFOLIO_SECTION_H

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
private:
    void initSection();
};

} // namespace yang

#endif // PORTFOLIO_SECTION_H
