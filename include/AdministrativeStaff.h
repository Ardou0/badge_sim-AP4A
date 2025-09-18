//
// Created by arman on 17/09/2025.
//

#ifndef BADGE_SIM_ADMINISTRATIVESTAFF_H
#define BADGE_SIM_ADMINISTRATIVESTAFF_H
#include "Person.h"
using namespace std;

class AdministrativeStaff : public Person {
public:
    AdministrativeStaff() = delete;
    AdministrativeStaff(const string& name, const string& surname) : Person(name, surname, "administrativeStaff") {};

    vector<string> getAccessRights() const override;
};



#endif //BADGE_SIM_ADMINISTRATIVESTAFF_H