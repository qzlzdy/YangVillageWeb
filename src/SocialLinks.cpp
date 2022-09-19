#include "SocialLinks.h"

#include <functional>
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WDialog.h>
#include <Wt/WFont.h>
#include <Wt/WLink.h>
#include <Wt/WPushButton.h>
#include <Wt/WVBoxLayout.h>

using namespace std;
using namespace Wt;
using namespace yang;

SocialLinks::SocialLinks(){
    setStyleClass("mt-3 text-center");

    WLink twitterLink("https://twitter.com/qzlzdy_yang");
    twitterLink.setTarget(LinkTarget::NewWindow);
    WAnchor *twitter = addNew<WAnchor>(twitterLink,
        "<i class=\"bi bi-twitter\"/>");
    setIconStyle(twitter);

    WLink githubLink("https://github.com/qzlzdy");
    githubLink.setTarget(LinkTarget::NewWindow);
    WAnchor *github = addNew<WAnchor>(githubLink,
        "<i class=\"bi bi-github\"/>");
    setIconStyle(github);

    WAnchor *wechat = addNew<WAnchor>(WLink(), "<i class=\"bi bi-wechat\"/>");
    setIconStyle(wechat);
    wechat->clicked().connect(bind(
        &SocialLinks::showDialog, this, "扫码加微信", "/images/wechat.png"));

    WAnchor *qq = addNew<WAnchor>(WLink(), "<i class=\"bi bi-quora\"/>");
    setIconStyle(qq);
    qq->clicked().connect(bind(
        &SocialLinks::showDialog, this, "扫码加QQ", "/images/tencentqq.png"));
}

void SocialLinks::setIconStyle(WWebWidget *icon){
    WFont font;
    font.setSize(24);
    icon->decorationStyle().setFont(font);
    icon->decorationStyle().setBackgroundColor(WColor(0x21, 0x24, 0x31));
    icon->setMargin(4, Side::Right);
    icon->resize(36, 36);
    icon->setStyleClass(
        "text-light p-0 text-center rounded-circle d-inline-block");
}

void SocialLinks::showDialog(const WString &title, const WLink &code){
    WDialog *dialog = addChild(make_unique<WDialog>(title));
    WVBoxLayout *contents =
        dialog->contents()->setLayout(make_unique<WVBoxLayout>());
    contents->addWidget(make_unique<WImage>(code, "二维码"));
    WPushButton *button = contents->addWidget(make_unique<WPushButton>("关闭"));
    button->setDefault(true);
    button->clicked().connect(dialog, &WDialog::accept);
    dialog->finished().connect([=](){
        removeChild(dialog);
    });
    dialog->show();
}
