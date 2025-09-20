//
// Created by Walle on 17/09/2025.
//

#ifndef BADGE_SIM_PERSON_H
#define BADGE_SIM_PERSON_H
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Person {
protected:
    string name;
    string surname;
    string occupation;
    vector<string> AccessRights;
    int hasExecption = 0;

public:
    Person() = delete;

    Person(string name, string surname, string occupation);

    virtual ~Person();

    string getName() const;

    string getOccupation() const;

    int getHasExecption() const;

    vector<string> getAccessRights() const;

    virtual void setExceptionalAccessRights(const string&);
    virtual void setExceptionalAccessRights(const vector<string>&);

    virtual void available() const = 0;
};


#endif //BADGE_SIM_PERSON_H
