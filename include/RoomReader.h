//
// Created by arman on 18/09/2025.
//

#ifndef BADGE_SIM_ROOMREADER_H
#define BADGE_SIM_ROOMREADER_H
#include "BadgeReader.h"


class RoomReader final : public BadgeReader{
    public:
    explicit RoomReader(const string& location) : BadgeReader(location, "room") {}
    void performReadAction() override {}
};


#endif //BADGE_SIM_ROOMREADER_H