//
// Created by Walle on 17/09/2025.
//

#include "../include/BadgeReader.h"
#include <thread>
#include <chrono>
#include <iostream>
#include <ostream>
#include "../include/Badge.h"

string BadgeReader::getLocation() const {
    return this->location;
}

string BadgeReader::getType() const {
    return this->type;
}

bool BadgeReader::readBadge(const Badge &badge) {
    int result = this->server.validateAccessRights(*this, badge);
    if (result == 0) {
        return false;
    } else {
        this->openDoor();
        return true;
    }
}

void BadgeReader::openDoor() {
    this->open = true;
    cout << "Opened Door at " << this->location << " of type " << this->type << endl;
    activeThreads.emplace_back([this]() {
        this_thread::sleep_for(chrono::seconds(this->timer));
        this->open = false;
        cout << "Closed Door at " << this->location << " of type " << this->type << endl;
    });
}

BadgeReader::~BadgeReader() {
    for (auto &t : activeThreads) {
        if (t.joinable()) {
            t.join();
        }
    }
}