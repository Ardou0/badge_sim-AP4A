//
// Created by Walle on 17/09/2025.
//

#ifndef BADGE_SIM_BADGEREADER_H
#define BADGE_SIM_BADGEREADER_H
#include <string>
#include <utility>
using namespace std;


class BadgeReader {
private:
    string location;
    string type;
    bool open;
    int timer;

public:
    BadgeReader() = delete;

    BadgeReader(string location, string type) : location(std::move(location)), type(std::move(type)),
                                                open(false), timer(5) {
    };

    virtual ~BadgeReader() = default;

    virtual void performReadAction() = 0;

    string getLocation() const;

    string getType() const;

    bool getStatus();

    void openDoor();
};


#endif //BADGE_SIM_BADGEREADER_H
