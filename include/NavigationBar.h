#ifndef NAVIGATIONBAR_H
#define NAVIGATIONBAR_H

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

}

#endif // NAVIGATIONBAR_H
