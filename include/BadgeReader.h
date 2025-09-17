//
// Created by Walle on 17/09/2025.
//

#ifndef BADGE_SIM_BADGEREADER_H
#define BADGE_SIM_BADGEREADER_H
#include <string>
using namespace std;


class BadgeReader {
private:
    int id;
    string location;
    string type;
public:
    string getLocation();
    string getType();
    void setLocation(string location);
    void setType(string type);
    int getId();
    void setId(int id);
};


#endif //BADGE_SIM_BADGEREADER_H