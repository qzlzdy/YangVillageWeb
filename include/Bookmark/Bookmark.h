#ifndef BOOKMARK_BOOKMARK_H
#define BOOKMARK_BOOKMARK_H

#include <Wt/WApplication.h>
#include <Wt/WEnvironment.h>

namespace yang{

class Bookmark: public Wt::WApplication{
public:
    Bookmark(const Wt::WEnvironment &env);
};

} // namespace yang

#endif // BOOKMARK_BOOKMARK_H
