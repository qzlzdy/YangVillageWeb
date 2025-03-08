#    YangVillage Website
#    Copyright (C) 2024  Qzlzdy
#
#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU Affero General Public License as published
#    by the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU Affero General Public License for more details.
#
#    You should have received a copy of the GNU Affero General Public License
#    along with this program.  If not, see <https://www.gnu.org/licenses/>.
add_executable(portfolio.wt
    main.cpp
    About.cpp
    Contact.cpp
    ContactFormModel.cpp
    ContactFormView.cpp
    Footer.cpp
    Header.cpp
    Home.cpp
    NavigationBar.cpp
    Portfolio.cpp
    Profile.cpp
    ProjectInfo.cpp
    Projects.cpp
    Resume.cpp
    Section.cpp
    Skills.cpp
    SocialLinks.cpp
)

target_link_libraries(portfolio.wt
    fcgi wt wtfcgi wtdbo wtdbosqlite3
)
