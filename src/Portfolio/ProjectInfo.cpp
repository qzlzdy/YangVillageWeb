#include "Portfolio/ProjectInfo.h"

#include <Wt/WAnchor.h>
#include <Wt/WLink.h>

using namespace std;
using namespace Wt;
using namespace yang;

WString yang::toIcon(const ProjectType &type){
    switch(type){
    case ProjectType::CPP:
        return "<i class=\"bi bi-file-earmark-binary\"/>";
    case ProjectType::EMBEDDED:
        return "<i class=\"bi bi-cpu\"/>";
    case ProjectType::JAVA:
        return "<i class=\"bi bi-filetype-java\"/>";
    case ProjectType::ANDROID:
        return "<i class=\"bi bi-android2\"/>";
    case ProjectType::PYTHON:
        return "<i class=\"bi bi-filetype-py\"/>";
    default:
        return "<i class=\"bi bi-file-earmark\"/>";
    }
}

unique_ptr<WTemplate> ProjectInfo::toWidget() const{
    auto widget = make_unique<WTemplate>(WWidget::tr("projectInfo-template"));
    widget->bindString("proj-type", toIcon(type));
    widget->bindString("proj-title", title);
    widget->bindString("proj-begin", begin.toString("yyyy-M"));
    if(!end.isNull()){
        widget->bindString("proj-end", end.toString("yyyy-M"));
    }
    else{
        widget->bindString("proj-end", "至今");
    }
    if(!repoAddr.empty()){
        widget->setCondition("has-src", true);
        WLink repoLink(repoAddr);
        repoLink.setTarget(LinkTarget::NewWindow);
        WAnchor *url = widget->bindWidget("proj-src",
            make_unique<WAnchor>(repoLink, repoName));
        url->setStyleClass("text-decoration-none");
    }
    if(!desc.empty()){
        widget->setCondition("has-desc", true);
        widget->bindString("proj-desc", desc);
    }
    return widget;
}
