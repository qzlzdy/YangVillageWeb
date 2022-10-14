#ifndef PROJECTDETAILS_H
#define PROJECTDETAILS_H

#include <Wt/WDate.h>
#include <Wt/WLink.h>
#include <Wt/WString.h>
#include <Wt/WTemplate.h>

namespace yang{

enum ProjectType{
    PROJ_NULL = 0,
    PROJ_ANDROID,
    PROJ_CPP,
    PROJ_EMBEDDED,
    PROJ_JAVA,
    PROJ_PYTHON
};

Wt::WString convertToIcon(const ProjectType &type);

struct ProjectInfo{
    Wt::WString title;
    ProjectType type;
    Wt::WDate from;
    Wt::WDate to;
    Wt::WLink repo;
    Wt::WString repoName;
};

class ProjectDetails: public Wt::WTemplate{
public:
    ProjectDetails(const ProjectInfo &info);
};

}

#endif // PROJECTDETAILS_H
