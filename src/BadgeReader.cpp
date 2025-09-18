//
// Created by Walle on 17/09/2025.
//

#include "../include/BadgeReader.h"
#include <thread>
#include <chrono>
#include <iostream>
#include <ostream>

string BadgeReader::getLocation() const {
    return this->location;
}

string BadgeReader::getType() const {
    return this->type;
}

bool BadgeReader::getStatus() {
    return this->open;
}

void BadgeReader::openDoor() {
    this->open = true;
    cout << "Opened Door at " << this->location << " of type " << this->type << endl;
    thread([this]() {
        std::this_thread::sleep_for(std::chrono::seconds(this->timer));
        this->open = false;
        cout << "Closed Door at " << this->location << " of type " << this->type << endl;
    }).detach();
}
