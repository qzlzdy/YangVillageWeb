#include "ProjectDetails.h"

#include <Wt/WAnchor.h>

using namespace std;
using namespace Wt;
using namespace yang;

WString yang::convertToIcon(const ProjectType &type){
    switch(type){
    case PROJ_ANDROID:
        return "<i class=\"bi bi-android2\"/>";
    case PROJ_CPP:
        return "<i class=\"bi bi-file-earmark-binary\"/>";
    case PROJ_EMBEDDED:
        return "<i class=\"bi bi-cpu\"/>";
    case PROJ_JAVA:
        return "<i class=\"bi bi-filetype-java\"/>";
    case PROJ_PYTHON:
        return "<i class=\"bi bi-filetype-py\"/>";
    default:
        return "<i class=\"bi bi-file-earmark\"/>";
    }
}

ProjectDetails::ProjectDetails(const ProjectInfo &info){
    setTemplateText(tr("projectDetails-template"));
    bindString("proj-type", convertToIcon(info.type));
    bindString("title", info.title);
    bindString("from-date", info.from.toString("yyyy-M"));
    bindString("to-date", info.to.toString("yyyy-M"));
    if(!info.repo.isNull()){
        setCondition("has-src", true);
        bindWidget("proj-src", make_unique<WAnchor>(info.repo, info.repoName));
    }
}
