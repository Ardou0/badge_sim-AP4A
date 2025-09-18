//
// Created by Walle on 17/09/2025.
//

#ifndef BADGE_SIM_BADGEREADER_H
#define BADGE_SIM_BADGEREADER_H
#include <string>
using namespace std;


class BadgeReader {
private:
    string location;
    string type;
    bool open;
    int timer;

public:
    BadgeReader() = delete;

    BadgeReader(const string location, const string type) : location(location), type(type),
                                                                    open(false), timer(5) {};

    ~BadgeReader() = default;

    string getLocation() const;

    string getType() const;

    bool getStatus();

    void openDoor();
};


#endif //BADGE_SIM_BADGEREADER_H
