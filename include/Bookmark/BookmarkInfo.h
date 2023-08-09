#ifndef BOOKMARK_BOOKMARKINFO_H
#define BOOKMARK_BOOKMARKINFO_H

#include <string>
#include <Wt/Dbo/Dbo.h>

namespace Dbo = Wt::Dbo;

namespace yang{

struct BookmarkInfo{
    template<class Action>
    void persist(Action &a);
    std::string catalog;
    std::string title;
    std::string desc;
    std::string url;
};

template<class Action>
void BookmarkInfo::persist(Action &a){
    Dbo::field(a, catalog, "catalog");
    Dbo::field(a, title, "title");
    Dbo::field(a, desc, "desc");
    Dbo::field(a, url, "url");
}

} // namespace yang

namespace Wt{

namespace Dbo{

template<>
struct dbo_traits<yang::BookmarkInfo>: public dbo_default_traits{
    static const char *versionField(){
        return nullptr; // Disable version field
    }
};

} // namespace Dbo

} // namespace Wt

#endif // BOOKMARK_BOOKMARKINFO_H
