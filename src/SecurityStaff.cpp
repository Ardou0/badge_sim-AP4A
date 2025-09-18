//
// Created by arman on 17/09/2025.
//

#include "../include/SecurityStaff.h"
#include "../include/utils.h"

vector<string> SecurityStaff::getAccessRights() const {
    return getPermissionsList("../config/permissions.csv", this->occupation);
}
