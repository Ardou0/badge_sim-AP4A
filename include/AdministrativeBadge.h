//
// Created by arman on 17/09/2025.
//

#ifndef BADGE_SIM_ADMINISTRATIVEBADGE_H
#define BADGE_SIM_ADMINISTRATIVEBADGE_H

#include "Badge.h"
#include "AdministrativeStaff.h"


class AdministrativeBadge final : public Badge {
public:
    explicit AdministrativeBadge(AdministrativeStaff& owner) : Badge(owner) {};
};


#endif //BADGE_SIM_ADMINISTRATIVEBADGE_H