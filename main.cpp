#include "include/Scheduler.h"
#include <iostream>
#include "include/Student.h"
#include "include/StudentBadge.h"
#include "include/RoomReader.h"
#include "include/Server.h"
using namespace std;

int main() {
    Server accessServer = Server();
    Student a = Student("John", "Michael");
    StudentBadge Ba = StudentBadge(a);
    RoomReader Br = RoomReader("classroom");

    cout << accessServer.validateAccessRights(Br, Ba);
    vector<string> auth = a.getAccessRights();
    for (string i: auth)
        std::cout << i << ' ';


    return 0;
}
