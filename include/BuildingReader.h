//
// Created by arman on 18/09/2025.
//

#ifndef BADGE_SIM_BUILDINGREADER_H
#define BADGE_SIM_BUILDINGREADER_H
#include "BadgeReader.h"
#include "Server.h"

class BuildingReader final : public BadgeReader{
public:
    explicit BuildingReader(const string& location, Server& s) : BadgeReader(location, "building", s) {}
    void available() const override {}
};


#endif //BADGE_SIM_BUILDINGREADER_H