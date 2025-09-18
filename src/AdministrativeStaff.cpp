//
// Created by arman on 17/09/2025.
//

#include "../include/AdministrativeStaff.h"
#include "../include/utils.h"

vector<string> AdministrativeStaff::getAccessRights() const {
    return getPermissionsList("../config/permissions.csv", this->occupation);
}
