#ifndef BOOKMARK_CLUSTER_H
#define BOOKMARK_CLUSTER_H

#include <string>
#include <Wt/WContainerWidget.h>
#include <Wt/WString.h>

namespace yang{

class Cluster: public Wt::WContainerWidget{
public:
    Cluster(const Wt::WString &title, const std::string &catalog);
private:
    std::unique_ptr<Wt::WContainerWidget>
    makeCard(const Wt::WString &title, const Wt::WString &desc,
             const std::string &url);
};

} // namespace yang

#endif // BOOKMARK_CLUSTER_H
