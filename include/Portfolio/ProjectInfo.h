#ifndef PORTFOLIO_PROJECTINFO_H
#define PORTFOLIO_PROJECTINFO_H

#include <memory>
#include <Wt/WDate.h>
#include <Wt/WString.h>
#include <Wt/WTemplate.h>
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/WtSqlTraits.h>

namespace Dbo = Wt::Dbo;

namespace yang{

enum class ProjectType{
    ALL = 0,
    CPP,
    EMBEDDED,
    JAVA,
    ANDROID,
    PYTHON
};

Wt::WString toIcon(const ProjectType &type);

class ProjectInfo{
public:
    ProjectInfo() = default;
    template<class Action>
    void persist(Action &a);
    std::unique_ptr<Wt::WTemplate> toWidget() const;
    ProjectType type;
    std::string title;
    Wt::WDate begin;
    Wt::WDate end;
    std::string repoAddr;
    std::string repoName;
    std::string desc;
};

template<class Action>
void ProjectInfo::persist(Action &a){
    Dbo::field(a, type, "type");
    Dbo::field(a, title, "title");
    Dbo::field(a, begin, "begin");
    Dbo::field(a, end, "end");
    Dbo::field(a, repoAddr, "repoAddr");
    Dbo::field(a, repoName, "repoName");
    Dbo::field(a, desc, "desc");
}

} // namespace yang

namespace Wt{

namespace Dbo{

template<>
struct dbo_traits<yang::ProjectInfo>: public dbo_default_traits{
    static const char *versionField(){
        return nullptr; // Disable version field
    }
};

} // namespace Dbo

} // namespace Wt

#endif // PORTFOLIO_PROJECTINFO_H
