//
// Created by Walle on 17/09/2025.
//

#ifndef BADGE_SIM_BADGEREADER_H
#define BADGE_SIM_BADGEREADER_H
#include <string>
#include <utility>
#include <thread>

#include "Badge.h"
#include "Server.h"
using namespace std;


class BadgeReader {
protected:
    string location;
    string type;
    bool open;
    int timer;
    Server server;
    vector<thread> activeThreads;

public:
    BadgeReader() = delete;

    BadgeReader(string location, string type, const Server& s) : location(std::move(location)), type(std::move(type)),
                                                open(false), timer(5), server(s) {
    };

    ~BadgeReader();

    virtual void performReadAction() = 0;

    string getLocation() const;

    string getType() const;

    bool readBadge(const Badge&);

    void openDoor();
};


#endif //BADGE_SIM_BADGEREADER_H
