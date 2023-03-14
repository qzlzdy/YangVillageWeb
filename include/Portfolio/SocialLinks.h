#ifndef PORTFOLIO_SOCIALLINKS_H
#define PORTFOLIO_SOCIALLINKS_H

#include <Wt/WContainerWidget.h>
#include <Wt/WLink.h>
#include <Wt/WString.h>
#include <Wt/WWebWidget.h>

namespace yang{

class SocialLinks: public Wt::WContainerWidget{
public:
    SocialLinks();
private:
    void setIconStyle(Wt::WWebWidget *icon);
    void showDialog(const Wt::WString &title, const Wt::WLink &code);
};

} // namespace yang

#endif // PORTFOLIO_SOCIALLINKS_H
