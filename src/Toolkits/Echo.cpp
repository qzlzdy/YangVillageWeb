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
