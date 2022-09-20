#ifndef NAVIGATIONBAR_H
#define NAVIGATIONBAR_H

#include <Wt/WContainerWidget.h>
#include <Wt/WNavigationBar.h>
#include <Wt/WString.h>
#include <Wt/WWebWidget.h>

namespace yang{

class NavigationBar: public Wt::WNavigationBar{
public:
    NavigationBar();
private:
    static const Wt::WString defaultStyleClass;
    void setActiveStyle(Wt::WWebWidget *widget);
    void setDeactiveStyle(Wt::WWebWidget *widget);
    void setDefaultStyle(Wt::WWebWidget *widget, bool isDeactive = true);
};

}

#endif // NAVIGATIONBAR_H
