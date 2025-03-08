/*    YangVillage Website
 *    Copyright (C) 2024  Qzlzdy
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU Affero General Public License as published
 *    by the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Affero General Public License for more details.
 *
 *    You should have received a copy of the GNU Affero General Public License
 *    along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
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
