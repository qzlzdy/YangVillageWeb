#ifndef PORTFOLIO_PORTFOLIO_H
#define PORTFOLIO_PORTFOLIO_H

#include <Wt/WApplication.h>
#include <Wt/WEnvironment.h>

namespace yang{

class Portfolio: public Wt::WApplication{
public:
    Portfolio(const Wt::WEnvironment &env);
};

} // namespace yang

#endif // PORTFOLIO_PORTFOLIO_H
