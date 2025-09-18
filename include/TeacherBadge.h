//
// Created by arman on 17/09/2025.
//

#ifndef BADGE_SIM_TEACHERBADGE_H
#define BADGE_SIM_TEACHERBADGE_H
#include "Badge.h"
#include "Teacher.h"


class TeacherBadge final : public Badge {
public:
    explicit TeacherBadge(Teacher& owner) : Badge(owner) {};
};


#endif //BADGE_SIM_TEACHERBADGE_H