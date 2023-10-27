#ifndef BROADCAST_BROADCAST_H
#define BROADCAST_BROADCAST_H

#include <Wt/WApplication.h>
#include <Wt/WEnvironment.h>

namespace yang{

class Broadcast: public Wt::WApplication{
public:
    Broadcast(const Wt::WEnvironment &env);
};

} // namespace yang

#endif // BROADCAST_BROADCAST_H
