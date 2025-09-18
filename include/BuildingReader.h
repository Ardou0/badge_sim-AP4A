//
// Created by arman on 18/09/2025.
//

#ifndef BADGE_SIM_BUILDINGREADER_H
#define BADGE_SIM_BUILDINGREADER_H
#include "BadgeReader.h"

class BuildingReader final : public BadgeReader{
public:
    explicit BuildingReader(const string& location) : BadgeReader(location, "building") {}
    void performReadAction() override {}
};


#endif //BADGE_SIM_BUILDINGREADER_H