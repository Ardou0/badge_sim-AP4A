//
// Created by arman on 17/09/2025.
//

#ifndef BADGE_SIM_STUDENT_H
#define BADGE_SIM_STUDENT_H
#include "Person.h"
using namespace std;

class Student : public Person {
public:
    Student() = delete;
    Student(const string name, const string surname) : Person(name, surname, "student") {};

    vector<string> getAccessRights() const override;
};


#endif //BADGE_SIM_STUDENT_H