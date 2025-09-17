//
// Created by Walle on 17/09/2025.
//

#ifndef BADGE_SIM_BADGE_H
#define BADGE_SIM_BADGE_H
#include "Person.h"

class Badge {
private:
    int id;
    Person owner;

public:
    Badge();

    Badge(int id, Person owner) : id(id), owner(owner) {
    };

    bool askAccess();
    int getAccessRights();
};


#endif //BADGE_SIM_BADGE_H
