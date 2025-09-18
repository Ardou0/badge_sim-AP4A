//
// Created by arman on 17/09/2025.
//

#include "../include/Teacher.h"
#include "../include/utils.h"

vector<string> Teacher::getAccessRights() const {
    return getPermissionsList("../config/permissions.csv", this->occupation);
}
