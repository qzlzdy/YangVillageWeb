#ifndef HOMEPAGE_HOMEPAGE_H
#define HOMEPAGE_HOMEPAGE_h

#include <Wt/WApplication.h>
#include <Wt/WEnvironment.h>

namespace yang{

class Homepage: public Wt::WApplication{
public:
    Homepage(const Wt::WEnvironment &env);
};

} // namespace yang

#endif // HOMEPAGE_HOMEPAGE_H
