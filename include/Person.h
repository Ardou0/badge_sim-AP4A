//
// Created by Walle on 17/09/2025.
//

#ifndef BADGE_SIM_PERSON_H
#define BADGE_SIM_PERSON_H
#include <string>
#include <vector>
using namespace std;

class Person {
protected:
    string name;
    string surname;
    string occupation;

public:
    Person() = delete;

    Person(string name, string surname, string occupation) : name(name), surname(surname), occupation(occupation) {
    };

    virtual ~Person();

    string getName() const;

    string getOccupation() const;

    virtual vector<string> getAccessRights() const = 0;
};


#endif //BADGE_SIM_PERSON_H
