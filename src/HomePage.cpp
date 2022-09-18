#include "HomePage.h"

#include <Wt/WBreak.h>
#include <Wt/WImage.h>
#include <Wt/WText.h>
#include <Wt/WVBoxLayout.h>

using namespace std;
using namespace Wt;
using namespace yang;

namespace {

class Avatar: public WContainerWidget{
public:
    Avatar(){
        setStyleClass("mx-auto");
        addWidget(
            make_unique<WImage>("images/avatar.png", "头像"));
        addNew<WBreak>();
        addWidget(make_unique<WText>("真是的、小学生真是太棒了!"));
    }
};

}

HomePage::HomePage(){
    WVBoxLayout *layout = setLayout(make_unique<WVBoxLayout>());
    layout->addWidget(make_unique<Avatar>());
}
