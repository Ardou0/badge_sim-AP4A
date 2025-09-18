//
// Created by Walle on 17/09/2025.
//

#include "../include/Person.h"

string Person::getName() const {
    string s = this->name  + " " + this->surname;
    return s;
}

string Person::getOccupation() const {
    return this->occupation;
}

Person::~Person() {}