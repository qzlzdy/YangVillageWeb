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
#ifndef BOOKMARK_BOOKMARKINFO_H
#define BOOKMARK_BOOKMARKINFO_H

#include <string>
#include <Wt/Dbo/Dbo.h>

namespace Dbo = Wt::Dbo;

namespace yang{

struct BookmarkInfo{
    template<class Action>
    void persist(Action &a);
    std::string catalog;
    std::string title;
    std::string desc;
    std::string url;
};

template<class Action>
void BookmarkInfo::persist(Action &a){
    Dbo::field(a, catalog, "catalog");
    Dbo::field(a, title, "title");
    Dbo::field(a, desc, "desc");
    Dbo::field(a, url, "url");
}

} // namespace yang

namespace Wt{

namespace Dbo{

template<>
struct dbo_traits<yang::BookmarkInfo>: public dbo_default_traits{
    static const char *versionField(){
        return nullptr; // Disable version field
    }
};

} // namespace Dbo

} // namespace Wt

#endif // BOOKMARK_BOOKMARKINFO_H
