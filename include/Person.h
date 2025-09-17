//
// Created by Walle on 17/09/2025.
//

#ifndef BADGE_SIM_PERSON_H
#define BADGE_SIM_PERSON_H
#include <string>
using namespace std;

class Person {
private:
    string name;
    string surname;
    string occupation;
public:
    Person() {};
    Person(string name, string surname, string occupation):name(name),surname(surname),occupation(occupation) {};
    string getOccupation();
    string getName();
    void setName(string name);
    void setSurname(string surname);
    void setOccupation(string occupation);
    int getAccessRights();
};


#endif //BADGE_SIM_PERSON_H