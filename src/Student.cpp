//
// Created by arman on 17/09/2025.
//

#include "../include/Student.h"
#include "../include/utils.h"

vector<string> Student::getAccessRights() const {
    //return getPermissionsList("../config/permissions.csv", this->occupation);
    return {"ab"};
}
