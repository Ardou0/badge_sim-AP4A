//
// Created by Walle on 17/09/2025.
//

#ifndef BADGE_SIM_SERVER_H
#define BADGE_SIM_SERVER_H
#include <string>
#include <vector>
class BadgeReader;
#include "Badge.h"
using namespace std;

class Server {
private:
    vector<vector<string>> config;
    string logFilePath;
    double &localTime;
public:
    Server(double &);
    ~Server() = default;
    void loadConfig();
    static std::string formatTimeDouble(double);
    void logEvent(const string&, const string&);
    bool validateAccessRights(const BadgeReader&, const Badge&);
};


#endif //BADGE_SIM_SERVER_H