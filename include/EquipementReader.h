//
// Created by arman on 20/09/2025.
//

#ifndef BADGE_SIM_EQUIPEMENTREADER_H
#define BADGE_SIM_EQUIPEMENTREADER_H
#include "BadgeReader.h"

class EquipementReader final : public BadgeReader{
public:
    explicit EquipementReader(const string& location, Server& s) : BadgeReader(location, "equipement", s) {}
    void available() const override {};
};


#endif //BADGE_SIM_EQUIPEMENTREADER_H