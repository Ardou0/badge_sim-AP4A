//
// Created by Walle on 17/09/2025.
//

#ifndef BADGE_SIM_BADGE_H
#define BADGE_SIM_BADGE_H
#include "Person.h"

class Badge {
private:
    Person &owner;

public:
    Badge(Person &owner) : owner(owner) {
    }

    virtual ~Badge() = default;

    // Délègue l'appel à la méthode virtuelle de Person
    virtual vector<string> getAccessRights() const {
        return owner.getAccessRights();
    }

    virtual void activeBadge() const = 0;

    const Person *getOwner() const { return &owner; }
};


#endif //BADGE_SIM_BADGE_H
