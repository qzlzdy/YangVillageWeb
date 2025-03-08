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
#include "Toolkits/Echo.h"

#include <Wt/Http/Response.h>

using namespace std;
using namespace Wt;
using namespace yang;

Echo::~Echo(){
    beingDeleted();
}

void Echo::handleRequest(const Http::Request &req, Http::Response &resp){
    const string *echo = req.getParameter("echo");
    if(!echo){
        resp.setStatus(400);
        resp.setMimeType("text/plain");
        resp.out() << "missing query parameter \"echo\"" << endl;
    }
    resp.setMimeType("text/plain");
    resp.out() << *echo << endl;
}
