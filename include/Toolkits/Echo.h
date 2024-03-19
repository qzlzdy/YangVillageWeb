#ifndef TOOLKITS_ECHO_H
#define TOOLKITS_ECHO_H

#include <Wt/WResource.h>

namespace yang{

class Echo: public Wt::WResource{
public:
    Echo() = default;
    ~Echo();
    void handleRequest(const Wt::Http::Request &req,
                       Wt::Http::Response &resp) override;
};

} // namespace yang

#endif // TOOLKITS_ECHO_H
