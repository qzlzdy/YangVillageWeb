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
#include "Portfolio/Portfolio.h"

#include <string>
#include <Wt/WAnchor.h>
#include <Wt/WBootstrap5Theme.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLink.h>
#include <Wt/WVBoxLayout.h>
#include "Portfolio/About.h"
#include "Portfolio/Contact.h"
#include "Portfolio/Footer.h"
#include "Portfolio/Header.h"
#include "Portfolio/Home.h"
#include "Portfolio/Projects.h"
#include "Portfolio/Resume.h"
#include "Portfolio/Skills.h"

using namespace std;
using namespace Wt;
using namespace yang;

namespace {

const WLink BootstrapIcon = "https://cdn.jsdelivr.net/npm/"
    "bootstrap-icons@1.10.0/font/bootstrap-icons.css";

} // namespace

Portfolio::Portfolio(const WEnvironment &env): WApplication(env){
    messageResourceBundle().use("/usr/share/yangvillage/template");
    setTheme(make_shared<WBootstrap5Theme>());
    useStyleSheet(BootstrapIcon);
    setTitle("羊村-村长室");

    WContainerWidget *contents =
        root()->addWidget(make_unique<WContainerWidget>());
    contents->setStyleClass("p-0");
    WVBoxLayout *main = contents->setLayout(make_unique<WVBoxLayout>());
    Home *home = main->addWidget(make_unique<Home>());
    About *about = main->addWidget(make_unique<About>());
    main->addWidget(make_unique<Skills>());
    Resume *resume = main->addWidget(make_unique<Resume>());
    Projects *projects = main->addWidget(make_unique<Projects>());
    Contact *contact = main->addWidget(make_unique<Contact>());

    Header *header = root()->addWidget(make_unique<Header>());
    root()->addWidget(make_unique<Footer>());

    static_cast<WAnchor *>
    (header->find("home-link"))->setLink("#" + home->id());
    static_cast<WAnchor *>
    (header->find("about-link"))->setLink("#" + about->id());
    static_cast<WAnchor *>
    (header->find("resume-link"))->setLink("#" + resume->id());
    static_cast<WAnchor *>
    (header->find("projects-link"))->setLink("#" + projects->id());
    static_cast<WAnchor *>
    (header->find("contact-link"))->setLink("#" + contact->id());
}
