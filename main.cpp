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
    RoomReader Br = RoomReader("theater", accessServer);

    cout << Br.readBadge(Ba) << endl;
    vector<string> auth = a.getAccessRights();
    for (const string& i: auth)
        std::cout << i << ' ';
    cout << endl;
    return 0;
}
