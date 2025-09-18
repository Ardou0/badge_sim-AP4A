//
// Created by arman on 17/09/2025.
//

#ifndef BADGE_SIM_TEACHER_H
#define BADGE_SIM_TEACHER_H
#include "Person.h"
using namespace std;

class Teacher : public Person {
public:
    Teacher() = delete;
    Teacher(const string& name, const string& surname) : Person(name, surname, "teacher") {};

    vector<string> getAccessRights() const override;
};


#endif //BADGE_SIM_TEACHER_H