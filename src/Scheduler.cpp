//
// Created by Walle on 17/09/2025.
//
#include "../include/Scheduler.h"
#include "../include/RoomReader.h"
#include "../include/EquipementReader.h"
#include "../include/BuildingReader.h"
#include "../include/Student.h"
#include "../include/Teacher.h"
#include "../include/AdministrativeStaff.h"
#include "../include/SecurityStaff.h"
#include "../include/StudentBadge.h"
#include "../include/AdministrativeBadge.h"
#include "../include/SecurityBadge.h"
#include "../include/TeacherBadge.h"
#include <iostream>
#include <algorithm>
#include <chrono>

Scheduler::Scheduler()
    : randomGenerator(std::chrono::system_clock::now().time_since_epoch().count()),
      accessServer(std::make_shared<Server>(localTime)) {
    initializeReaders();
    initializeBadges();
}

void Scheduler::initializeReaders() {
    readers.push_back(std::make_shared<RoomReader>("classroom", *accessServer));
    readers.push_back(std::make_shared<RoomReader>("labs", *accessServer));
    readers.push_back(std::make_shared<EquipementReader>("computer", *accessServer));
    readers.push_back(std::make_shared<BuildingReader>("belfort", *accessServer));
}

void Scheduler::initializeBadges() {
    // Créez des objets Person et stockez-les dans le vecteur people
    auto student1 = std::make_shared<Student>("Alice", "Plantier");
    people.push_back(student1);
    badges.push_back(std::make_shared<StudentBadge>(*student1));

    auto student2 = std::make_shared<Student>("Arthur", "Rouget");
    student2->setExceptionalAccessRights("computer");
    people.push_back(student2);
    badges.push_back(std::make_shared<StudentBadge>(*student2));

    auto teacher = std::make_shared<Teacher>("Xavier", "Dupont");
    people.push_back(teacher);
    badges.push_back(std::make_shared<TeacherBadge>(*teacher));

    auto admin = std::make_shared<AdministrativeStaff>("Benedict", "Martin");
    people.push_back(admin);
    badges.push_back(std::make_shared<AdministrativeBadge>(*admin));

    auto security = std::make_shared<SecurityStaff>("Jean", "Claude");
    people.push_back(security);
    badges.push_back(std::make_shared<SecurityBadge>(*security));
}

void Scheduler::simulateRandomDay() {
    if (badges.empty() || readers.empty()) {
        std::cerr << "Not any badge or readers available." << std::endl;
        return;
    }

    std::exponential_distribution<double> timeBetweenEvents(0.2); // 5 événements/heure en moyenne
    double currentTime = 8.0; // Début à 8h
    while (currentTime <= 24.0) {
        localTime = currentTime;
        // Simuler des pics d'activité entre 8h-10h et 16h-18h
        if ((currentTime >= 8.0 && currentTime <= 10.0) || (currentTime >= 16.0 && currentTime <= 18.0)) {
            timeBetweenEvents = std::exponential_distribution<double>(1); // 20 événements/heure
        } else {
            timeBetweenEvents = std::exponential_distribution<double>(0.4); // 8 événements/heure
        }

        simulateRandomAccessEvent();
        double delay = timeBetweenEvents(randomGenerator);
        currentTime += delay;
        std::cout << currentTime << endl;
    }
}

void Scheduler::simulateRandomWeek() {
    for (int i = 1; i <= 5; i++) {
        this->simulateRandomDay();
    }
}


void Scheduler::simulateRandomAccessEvent() {
    if (badges.empty() || readers.empty()) {
        return;
    }

    std::uniform_int_distribution<size_t> badgeDist(0, badges.size() - 1);
    std::uniform_int_distribution<size_t> readerDist(0, readers.size() - 1);

    auto badge = badges[badgeDist(randomGenerator)];
    auto reader = readers[readerDist(randomGenerator)];

    simulateAccessEvent(badge, reader);
}

void Scheduler::simulateAccessEvent(const std::shared_ptr<Badge>& badge, const std::shared_ptr<BadgeReader>& reader) {
    if (!badge || !reader) {
        return;
    }

    if (bool accessGranted = reader->readBadge(*badge)) {
        std::cout << "Access granted for " << badge->getOwner()->getName()
                  << " at " << reader->getLocation() << std::endl;
    } else {
        std::cout << "Access denied for " << badge->getOwner()->getName()
                  << " at " << reader->getLocation() << std::endl;
    }
}

void Scheduler::addReader(const std::shared_ptr<BadgeReader>& reader) {
    readers.push_back(reader);
}

void Scheduler::addBadge(const std::shared_ptr<Badge>& badge) {
    badges.push_back(badge);
}

const std::vector<std::shared_ptr<BadgeReader>>& Scheduler::getReaders() const {
    return readers;
}

const std::vector<std::shared_ptr<Badge>>& Scheduler::getBadges() const {
    return badges;
}