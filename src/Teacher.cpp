//
// Created by arman on 17/09/2025.
//

#include "../include/Teacher.h"

vector<string> Teacher::getAccessRights() const {
    return {
        "classroom",
        "teachers_lounge",
        "library",
        "labs",
        "cafeteria",
        "teachers_parking",
        "exam_hall",
        "educational_resources_room",
        "after_hours_access"
    };
}
