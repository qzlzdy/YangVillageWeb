#include "Portfolio/Projects.h"

#include <algorithm>
#include <functional>
#include <Wt/WColor.h>
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WFont.h>
#include <Wt/WVBoxLayout.h>

using namespace std;
using namespace Wt;
using namespace yang;

namespace {

const ProjectInfo INSTGRAM_CRAWL = {
    "基于Scrapy + MongoDB的Instgram爬虫",
    PROJ_PYTHON,
    WDate(2018, 9, 1),
    WDate(2019, 1, 1),
    WLink()
};

const ProjectInfo CRAWL_BACKEND = {
    "基于Spring boot + MySQL的爬虫后台",
    PROJ_JAVA,
    WDate(2019, 3, 1),
    WDate(2019, 7, 1),
    WLink()
};

const ProjectInfo KNOWLEDGE_GRAPH = {
    "基于Protege + D2RQ + Apache Jena Fuseki的知识图谱应用",
    PROJ_PYTHON,
    WDate(2019, 9, 1),
    WDate(2020, 1 ,1),
    WLink()
};

const ProjectInfo STM32_GAME = {
    "基于STM32F207VCT6的触摸屏双人棋类游戏",
    PROJ_EMBEDDED,
    WDate(2019, 9, 1),
    WDate(2020, 1, 1),
    WLink()
};

const ProjectInfo INROOM_NAVI_APP = {
    "基于Android + 百度地图SDK + 知识图谱的可语音交互室内导航APP",
    PROJ_ANDROID,
    WDate(2020, 3, 1),
    WDate(2020, 6, 1),
    "https://github.com/longjie1107/AndroidShopQuery.git",
    "AndroidShopQuery"
};

const ProjectInfo ANIVATAR = {
    "基于生成对抗网络的动漫头像生成软件开发",
    PROJ_PYTHON,
    WDate(2020, 12, 1),
    WDate(2021, 4, 1),
    "https://github.com/qzlzdy/Anivatar.git",
    "Anivatar"
};

const ProjectInfo EHDU_CHESS = {
    "基于STM32F207的触摸屏国际象棋游戏",
    PROJ_EMBEDDED,
    WDate(2022, 3, 1),
    WDate(2022, 6, 1),
    "https://github.com/qzlzdy/EhduChess.git",
    "EhduChess"
};

const ProjectInfo EHDU_BADAPPLE = {
    "Bad Apple杭电版",
    PROJ_EMBEDDED,
    WDate(2022, 3, 1),
    WDate(2022, 6, 1),
    "https://github.com/qzlzdy/EhduBadApple.git",
    "EhduBadApple"
};

const ProjectInfo NEKO_CHAN = {
    "猫猫ちゃん色图机器人",
    PROJ_PYTHON,
    WDate(2018, 12, 18),
    WDate::currentServerDate(),
    "https://github.com/qzlzdy/Neko-Chan2.git",
    "Neko-Chan2"
};

const ProjectInfo YANG_VILLAGE = {
    "羊村网站",
    PROJ_CPP,
    WDate(2022, 9, 17),
    WDate::currentServerDate(),
    "https://github.com/qzlzdy/YangVillageWeb.git",
    "YangVillageWeb"
};

const ProjectInfo DOLPHINDB_PLUGIN = {
    "Dolphin DB插件",
    PROJ_CPP,
    WDate(2021, 2, 8),
    WDate(2021, 6, 25),
    "https://github.com/dolphindb/DolphinDBPlugin.git",
    "DolphinDBPlugin"
};

const ProjectInfo MISC = {
    "其他各种代码片段",
    PROJ_CPP,
    WDate(2017, 9, 18),
    WDate::currentServerDate(),
    "https://github.com/qzlzdy/Daily-Code.git",
    "Daily-Code"
};

}

const vector<const ProjectInfo *> Projects::projects = {
    &ANIVATAR,
    &YANG_VILLAGE,
    &EHDU_BADAPPLE,
    &NEKO_CHAN,
    &DOLPHINDB_PLUGIN,
    &EHDU_CHESS,
    &INROOM_NAVI_APP,
    &KNOWLEDGE_GRAPH,
    &CRAWL_BACKEND,
    &INSTGRAM_CRAWL,
    &STM32_GAME,
    &MISC
};

Projects::Projects(): Section("projects"){
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

    WText *android = addFilter(filters, "Android");
    android->clicked().connect(bind(&Projects::filterClicked, this, android));

    WText *cpp = addFilter(filters, "C/C++");
    cpp->clicked().connect(bind(&Projects::filterClicked, this, cpp));

    WText *embedded = addFilter(filters, "Embedded");
    embedded->clicked().connect(bind(&Projects::filterClicked, this, embedded));

    WText *java = addFilter(filters, "Java");
    java->clicked().connect(bind(&Projects::filterClicked, this, java));

    WText *python = addFilter(filters, "Python");
    python->clicked().connect(bind(&Projects::filterClicked, this, python));

    currentActive = nullptr;
    projectList = addWidget(make_unique<WContainerWidget>())
        ->setLayout(make_unique<WVBoxLayout>());
    filterClicked(all);
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
    if(currentActive == source){
        return;
    }
    if(currentActive != nullptr){
        setDeactiveStyle(currentActive);
    }
    setActiveStyle(source);
    currentActive = source;
    while(projectList->count() > 0){
        projectList->removeItem(projectList->itemAt(0));
    }
    if(currentActive->text() == "All"){
        for_each(projects.begin(), projects.end(), [&](const ProjectInfo *info){
            projectList->addWidget(make_unique<ProjectDetails>(*info));
        });
    }
    else if(currentActive->text() == "Android"){
        for_each(projects.begin(), projects.end(), [&](const ProjectInfo *info){
            if(info->type == PROJ_ANDROID){
                projectList->addWidget(make_unique<ProjectDetails>(*info));
            }
        });
    }
    else if(currentActive->text() == "C/C++"){
        for_each(projects.begin(), projects.end(), [&](const ProjectInfo *info){
            if(info->type == PROJ_CPP){
                projectList->addWidget(make_unique<ProjectDetails>(*info));
            }
        });
    }
    else if(currentActive->text() == "Embedded"){
        for_each(projects.begin(), projects.end(), [&](const ProjectInfo *info){
            if(info->type == PROJ_EMBEDDED){
                projectList->addWidget(make_unique<ProjectDetails>(*info));
            }
        });
    }
    else if(currentActive->text() == "Java"){
        for_each(projects.begin(), projects.end(), [&](const ProjectInfo *info){
            if(info->type == PROJ_JAVA){
                projectList->addWidget(make_unique<ProjectDetails>(*info));
            }
        });
    }
    else if(currentActive->text() == "Python"){
        for_each(projects.begin(), projects.end(), [&](const ProjectInfo *info){
            if(info->type == PROJ_PYTHON){
                projectList->addWidget(make_unique<ProjectDetails>(*info));
            }
        });
    }
}
