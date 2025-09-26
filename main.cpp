#include <iostream>
#include "include/Scheduler.h"
using namespace std;

int main() {
    Scheduler s = Scheduler();
    s.simulateRandomDay();
    return 0;

    //Todo
    //Add coplien's form to all
    //Edit Server to handle access during work hours (already done) and out work hours (for allowing security but not others)
    //Pass current time to server so logs events have both Real and Fake Time
    ///use references to init time in scheduler and pass it to server so server can access value anytime without passing it everytime we log an event
}
