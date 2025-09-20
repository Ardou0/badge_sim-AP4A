//
// Created by Walle on 17/09/2025.
//

#include <utility>

#include "../include/utils.h"
#include "../include/Person.h"
using namespace std;

Person::Person(string name, string surname, string occupation) {
    this->name = move(name);
    this->surname = move(surname);
    this->occupation = move(occupation);
    this->AccessRights = getPermissionsList("../config/permissions.csv", this->occupation);
}


string Person::getName() const {
    string s = this->name + " " + this->surname;
    return s;
}

string Person::getOccupation() const {
    return this->occupation;
}

int Person::getHasExecption() const {
    return this->hasExecption;
}

vector<string> Person::getAccessRights() const {
    return this->AccessRights;
}

void Person::setExceptionalAccessRights(const string &accessRights) {
    vector<string> exception = getPermissionsList("../config/permissions.csv", "E" + this->occupation);
    for (const string &auth: exception) {
        if (auth == accessRights) {
            this->AccessRights.push_back(accessRights);
            this->hasExecption = 1;
        }
    }
}

void Person::setExceptionalAccessRights(const vector<string> &accessRights) {
    vector<string> exception = getPermissionsList("../config/permissions.csv", "E" + this->occupation);
    for (const string &access: accessRights) {
        for (const string &auth: exception) {
            if (auth == access) {
                this->AccessRights.push_back(access);
                this->hasExecption = 1;
            }
        }
    }
}

Person::~Person() {
}
