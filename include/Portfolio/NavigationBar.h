#ifndef PORTFOLIO_NAVIGATIONBAR_H
#define PORTFOLIO_NAVIGATIONBAR_H

#include <Wt/WAnchor.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WNavigationBar.h>
#include <Wt/WString.h>

namespace yang{

class NavigationBar: public Wt::WNavigationBar{
public:
    NavigationBar();
private:
    static const Wt::WString defaultStyleClass;
    void setActiveStyle(Wt::WAnchor *widget);
    void setDeactiveStyle(Wt::WAnchor *widget);
    void setDefaultStyle(Wt::WAnchor *widget, bool isDeactive = true);
    void menuClicked(Wt::WAnchor *source);
    Wt::WAnchor *currentActive;
};

} // namespace yang

#endif // PORTFOLIO_NAVIGATIONBAR_H
