#ifndef PROJECTDETAILS_H
#define PROJECTDETAILS_H

#include <Wt/WDate.h>
#include <Wt/WString.h>
#include <Wt/WTemplate.h>

namespace yang{

struct ProjectInfo{
    Wt::WString title;
    Wt::WDate from;
    Wt::WDate to;
};

class ProjectDetails: public Wt::WTemplate{
public:
    ProjectDetails(const ProjectInfo &info);
};

}

#endif // PROJECTDETAILS_H
