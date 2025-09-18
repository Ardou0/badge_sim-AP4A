//
// Created by arman on 17/09/2025.
//

#ifndef BADGE_SIM_SECURITYSTAFF_H
#define BADGE_SIM_SECURITYSTAFF_H
#include "Person.h"
using namespace std;

class SecurityStaff : public Person {
public:
    SecurityStaff() = delete;
    SecurityStaff(const string& name, const string& surname) : Person(name, surname, "security") {};

    vector<string> getAccessRights() const override;
};


#endif //BADGE_SIM_SECURITYSTAFF_H