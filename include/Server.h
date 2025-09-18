//
// Created by Walle on 17/09/2025.
//

#ifndef BADGE_SIM_SERVER_H
#define BADGE_SIM_SERVER_H
#include <string>
#include <vector>
#include "BadgeReader.h"
#include "Badge.h"
using namespace std;

class Server {
private:
    vector<vector<string>> config;
    string logFilePath;
public:
    Server();
    ~Server() = default;
    void loadConfig();
    void logEvent(const string&, const string&);
    bool validateAccessRights(const BadgeReader&, const Badge&);
};


#endif //BADGE_SIM_SERVER_H