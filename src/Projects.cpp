#include "Projects.h"

#include <functional>
#include <Wt/WColor.h>
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WFont.h>
#include <Wt/WVBoxLayout.h>
#include "ProjectDetails.h"

using namespace std;
using namespace Wt;
using namespace yang;

namespace {

const ProjectInfo PROJ_INST_CRAWL = {
    "基于Scrapy + MongoDB的Instgram爬虫",
    WDate(2018, 9, 1),
    WDate(2019, 1, 1)
};

const ProjectInfo PROJ_CRAWL_BACKEND = {
    "基于Spring boot + MySQL的爬虫后台",
    WDate(2019, 3, 1),
    WDate(2019, 7, 1)
};

const ProjectInfo PROJ_KGRAPH = {
    "基于Protege + D2RQ + Apache Jena Fuseki的知识图谱应用",
    WDate(2019, 9, 1),
    WDate(2020, 1 ,1)
};

const ProjectInfo PROJ_STM32 = {
    "基于STM32F207VCT6的触摸屏双人棋类游戏",
    WDate(2019, 9, 1),
    WDate(2020, 1, 1)
};

const ProjectInfo PROJ_NAVI_APP = {
    "基于Android + 百度地图SDK + 知识图谱的可语音交互室内导航APP",
    WDate(2020, 3, 1),
    WDate(2020, 6, 1)
};

const ProjectInfo PROJ_ANIVATAR = {
    "基于生成对抗网络的动漫头像生成软件开发",
    WDate(2020, 12, 1),
    WDate(2021, 4, 1)
};

const ProjectInfo PROJ_STM32_CHESS = {
    "基于STM32F207的触摸屏国际象棋游戏",
    WDate(2022, 3, 1),
    WDate(2022, 6, 1)
};

const ProjectInfo PROJ_BAD_APPLE = {};

}

Projects::Projects(){
    addSectionTitle("项目经历");
    WContainerWidget *bar = addWidget(make_unique<WContainerWidget>());
    bar->setMargin(0, Side::Top);
    bar->setMargin(35, Side::Bottom);
    bar->setMargin(WLength(), Side::Left | Side::Right);
    bar->decorationStyle().setBackgroundColor(WColor(0xff, 0xff, 0xff));
    bar->setStyleClass("row col-lg-12 d-flex justify-content-center py-0 px-3 "
        "text-center rounded-pill");
    WHBoxLayout *filters = bar->setLayout(make_unique<WHBoxLayout>());

    WText *all = addFilter(filters, "All");
    setActiveStyle(all);
    all->clicked().connect(bind(&Projects::filterClicked, this, all));

    WText *cpp = addFilter(filters, "C/C++");
    cpp->clicked().connect(bind(&Projects::filterClicked, this, cpp));

    WText *java = addFilter(filters, "Java");
    java->clicked().connect(bind(&Projects::filterClicked, this, java));

    WText *python = addFilter(filters, "Python");
    python->clicked().connect(bind(&Projects::filterClicked, this, python));

    WText *sql = addFilter(filters, "SQL");
    sql->clicked().connect(bind(&Projects::filterClicked, this, sql));

    currentActive = all;

    WVBoxLayout *projects = addWidget(make_unique<WContainerWidget>())
        ->setLayout(make_unique<WVBoxLayout>());
    projects->addWidget(make_unique<ProjectDetails>(PROJ_INST_CRAWL));
    projects->addWidget(make_unique<ProjectDetails>(PROJ_CRAWL_BACKEND));
    projects->addWidget(make_unique<ProjectDetails>(PROJ_KGRAPH));
    projects->addWidget(make_unique<ProjectDetails>(PROJ_STM32));
    projects->addWidget(make_unique<ProjectDetails>(PROJ_NAVI_APP));
    projects->addWidget(make_unique<ProjectDetails>(PROJ_ANIVATAR));
    projects->addWidget(make_unique<ProjectDetails>(PROJ_STM32_CHESS));
}

WText *Projects::addFilter(WHBoxLayout *container, const WString &text){
    WText *filter = container->addWidget(make_unique<WText>(text));
    setDefaultStyle(filter);
    return filter;
}

void Projects::setActiveStyle(WText *filter){
    filter->decorationStyle().setForegroundColor(WColor(0x14, 0x9d, 0xdd));
}

void Projects::setDeactiveStyle(WText *filter){
    filter->decorationStyle().setForegroundColor(WColor(0x27, 0x28, 0x29));
}

void Projects::setDefaultStyle(WText *filter){
    WFont font;
    font.setSize(14);
    font.setWeight(FontWeight::Value, 600);
    filter->decorationStyle().setFont(font);
    filter->decorationStyle().setCursor(Cursor::PointingHand);
    filter->setMargin(5, Side::Bottom);
    filter->setStyleClass("d-inline-block py-2 px-3 text-uppercase");
    setDeactiveStyle(filter);
}

void Projects::filterClicked(WText *source){
    setDeactiveStyle(currentActive);
    setActiveStyle(source);
    currentActive = source;
}
