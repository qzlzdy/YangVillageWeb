#include "Portfolio.h"

#include <Wt/WBootstrap5Theme.h>
#include <Wt/WBorder.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WImage.h>

using namespace std;
using namespace Wt;
using namespace yang;

namespace {

class Profile: public WContainerWidget{
public:
    Profile(){
        WImage *avatar = addNew<WImage>("images/avatar.png", "头像");
        avatar->setStyleClass("d-block img_fluid rounded-circle my-3 mx-auto");
        avatar->setWidth(WLength(120));
        avatar->decorationStyle()
            .setBorder(WBorder(BorderStyle::Solid, 8, WColor(0x2c, 0x2f, 0x3f)));
    }
};

class Header: public WContainerWidget{
public:
    Header(){
        setStyleClass("position-fixed start-0 h-100 d-flex flex-column");
        setWidth(WLength(300));
        decorationStyle().setBackgroundColor(WColor(0x04, 0x0b, 0x014));
        addWidget(make_unique<Profile>());
    }
};

}

Portfolio::Portfolio(const WEnvironment &env): WApplication(env){
    // if(env.urlScheme() != "https"){
    //     redirect("https://" + env.hostName() + url());
    //     return;
    // }
    setTheme(make_shared<WBootstrap5Theme>());
    setTitle("羊村");
    root()->addWidget(make_unique<Header>());
}
