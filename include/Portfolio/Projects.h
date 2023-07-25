#ifndef PORTFOLIO_PROJECTS_H
#define PORTFOLIO_PROJECTS_H

#include <Wt/WHBoxLayout.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WText.h>
#include <Wt/WString.h>
#include "Section.h"

namespace yang{

class Projects: public Section{
public:
    Projects();
private:
    Wt::WText *addFilter(Wt::WHBoxLayout *container, const Wt::WString &text);
    void setActiveStyle(Wt::WText *filter);
    void setDeactiveStyle(Wt::WText *filter);
    void setDefaultStyle(Wt::WText *filter);
    void filterClicked(Wt::WText *source);
    Wt::WText *currentActive;
    Wt::WVBoxLayout *projectList;
};

} // namespace yang

#endif // PORTFOLIO_PROJECTS_H
