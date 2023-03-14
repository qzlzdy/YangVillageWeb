#include "Portfolio/Header.h"

#include <Wt/WColor.h>
#include <Wt/WCssDecorationStyle.h>
#include "Portfolio/NavigationBar.h"
#include "Portfolio/Profile.h"
#include "Portfolio/SocialLinks.h"

using namespace std;
using namespace Wt;
using namespace yang;

Header::Header(){
    setPositionScheme(PositionScheme::Fixed);
    setOffsets(0, Side::Top | Side:: Bottom | Side::Left);
    setWidth(300);
    decorationStyle().setBackgroundColor(WColor(0x04, 0x0b, 0x014));
    setStyleClass("py-0 px-3 d-flex flex-column");
    addWidget(make_unique<Profile>());
    addWidget(make_unique<SocialLinks>());
    addWidget(make_unique<NavigationBar>());
}
