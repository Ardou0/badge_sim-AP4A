//
// Created by Walle on 17/09/2025.
//

#ifndef BADGE_SIM_SERVER_H
#define BADGE_SIM_SERVER_H
#include <string>
using namespace std;

class Server {
private:
    string logFilePath;
public:
    Server();
    ~Server();
    void loadConfig();
    void logEvent();
    void validateAccessRights();
};


#endif //BADGE_SIM_SERVER_H