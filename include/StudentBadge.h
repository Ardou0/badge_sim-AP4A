//
// Created by arman on 17/09/2025.
//

#ifndef BADGE_SIM_STUDENTBADGE_H
#define BADGE_SIM_STUDENTBADGE_H
#include "Badge.h"
#include "Student.h"

class StudentBadge final : public Badge {
public:
    explicit StudentBadge(Student& owner) : Badge(owner) {};
    void activeBadge() const override {}
};



#endif //BADGE_SIM_STUDENTBADGE_H