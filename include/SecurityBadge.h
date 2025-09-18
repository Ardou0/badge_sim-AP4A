//
// Created by arman on 17/09/2025.
//

#ifndef BADGE_SIM_SECURITYBADGE_H
#define BADGE_SIM_SECURITYBADGE_H
#include "Badge.h"
#include "SecurityStaff.h"

class SecurityBadge final : public Badge {
    explicit SecurityBadge(SecurityStaff& owner) : Badge(owner) {};
};


#endif //BADGE_SIM_SECURITYBADGE_H