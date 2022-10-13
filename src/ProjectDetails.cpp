#include "ProjectDetails.h"

using namespace std;
using namespace Wt;
using namespace yang;

ProjectDetails::ProjectDetails(const ProjectInfo &info){
    setTemplateText(tr("projectDetails-template"));
    bindString("title", info.title);
    bindString("from-date", info.from.toString("yyyy-M"));
    bindString("to-date", info.to.toString("yyyy-M"));
}
