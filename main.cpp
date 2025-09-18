#include "include/Scheduler.h"
#include <iostream>
#include "include/Student.h"
#include "include/StudentBadge.h"
#include "include/BadgeReader.h"
#include "include/Server.h"
using namespace std;

int main() {
    Server accessServer = Server();
    Student a = Student("John", "Michael");
    StudentBadge Ba = StudentBadge(a);
    BadgeReader Br = BadgeReader("ab", "door");

    cout << accessServer.validateAccessRights(Br, Ba);
    vector<string> auth = a.getAccessRights();
    for (string i: auth)
        std::cout << i << ' ';

    return 0;
}