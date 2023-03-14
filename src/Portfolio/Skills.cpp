#include "Portfolio/Skills.h"

#include <Wt/WColor.h>
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WFont.h>
#include <Wt/WGridLayout.h>

using namespace std;
using namespace Wt;
using namespace yang;

Skills::Skills(){
    addSectionTitle("专业技能");
    WContainerWidget *content = addWidget(make_unique<WContainerWidget>());
    WGridLayout *grid = content->setLayout(make_unique<WGridLayout>());
    grid->setHorizontalSpacing(20);
    auto addGridCell = [=](int row, int column){
        WContainerWidget *cell = grid->addWidget(
            make_unique<WContainerWidget>(), row, column);
        cell->setHeight(80);
        cell->setStyleClass("d-block");
        return cell;
    };

    WContainerWidget *cpp = addGridCell(0, 0);
    addLabel(cpp, "C++ &amp; STL");
    addIndicator(cpp, "100%");
    addProgressBar(cpp, 100);

    WContainerWidget *cmake = addGridCell(0, 1);
    addLabel(cmake, "CMake");
    addIndicator(cmake, "95%");
    addProgressBar(cmake, 95);

    WContainerWidget *linux = addGridCell(1, 0);
    addLabel(linux, "Linux");
    addIndicator(linux, "90%");
    addProgressBar(linux, 90);

    WContainerWidget *qt = addGridCell(1, 1);
    addLabel(qt, "Qt");
    addIndicator(qt, "80%");
    addProgressBar(qt, 80);

    WContainerWidget *git = addGridCell(2, 0);
    addLabel(git, "Git");
    addIndicator(git, "70%");
    addProgressBar(git, 70);

    WContainerWidget *sql = addGridCell(2, 1);
    addLabel(sql, "SQL");
    addIndicator(sql, "70%");
    addProgressBar(sql, 70);

    WContainerWidget *doxygen = addGridCell(3, 0);
    addLabel(doxygen, "Doxygen");
    addIndicator(doxygen, "50%");
    addProgressBar(doxygen, 50);

    WContainerWidget *latex = addGridCell(3, 1);
    addLabel(latex, "LaTeX");
    addIndicator(latex, "55%");
    addProgressBar(latex, 55);

    WContainerWidget *driving = addGridCell(4, 0);
    addLabel(driving, "机动车驾驶");
    addIndicator(driving, "75%");
    addProgressBar(driving, 75);

    WContainerWidget *japanese = addGridCell(4, 1);
    addLabel(japanese, "日本語");
    addIndicator(japanese, "80%");
    addProgressBar(japanese, 80);

    WContainerWidget *english = addGridCell(5, 0);
    addLabel(english, "English");
    addIndicator(english, "60%");
    addProgressBar(english, 60);

    grid->setColumnStretch(0, 6);
    grid->setColumnStretch(1, 6);
}

WText *Skills::addLabel(WContainerWidget *container, const WString &text){
    WText *label = container->addWidget(make_unique<WText>(text));
    label->setMargin(6, Side::Bottom);
    label->setMargin(0, Side::Top | Side::Left | Side::Right);
    WFont font;
    font.setWeight(FontWeight::Value, 600);
    font.setFamily(FontFamily::SansSerif);
    font.setSize(24);
    label->decorationStyle().setFont(font);
    label->decorationStyle().setForegroundColor(WColor(0x05, 0x0d, 0x18));
    label->setStyleClass("p-0 text-uppercase d-block");
    return label;
}

WText *Skills::addIndicator(WContainerWidget *container, const WString &text){
    WText *indicator = addLabel(container, text);
    WFont font;
    font.setSize(24);
    indicator->decorationStyle().setFont(font);
    indicator->setStyleClass("float-end");
    return indicator;
}

WProgressBar *Skills::addProgressBar(WContainerWidget *container, int progress){
    WProgressBar *bar = container->addWidget(make_unique<WProgressBar>());
    bar->setRange(0, 100);
    bar->setValue(progress);
    bar->setHeight(10);
    bar->decorationStyle().setBackgroundColor(WColor(0xdc, 0xe8, 0xf8));
    bar->decorationStyle().setForegroundColor(WColor(0x14, 0x9d, 0xdd));
    bar->setFormat("");
    bar->setStyleClass("w-75");
    return bar;
}
