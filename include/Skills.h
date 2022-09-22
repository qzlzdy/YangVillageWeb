#ifndef SKILLS_H
#define SKILLS_H

#include <Wt/WProgressBar.h>
#include <Wt/WText.h>
#include "Section.h"

namespace yang{

class Skills: public Section{
public:
    Skills();
private:
    Wt::WText *addLabel(Wt::WContainerWidget *container,
                        const Wt::WString &text);
    Wt::WText *addIndicator(Wt::WContainerWidget *container,
                            const Wt::WString &text);
    Wt::WProgressBar *addProgressBar(Wt::WContainerWidget *container,
                                     int progress);
};

}

#endif // SKILLS_H
