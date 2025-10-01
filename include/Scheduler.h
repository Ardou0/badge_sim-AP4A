// Scheduler.h
#pragma once
#include <vector>
#include <memory>
#include <random>
#include "Server.h"
#include "BadgeReader.h"
#include "Badge.h"
#include "Person.h"

class Scheduler {
private:
    std::vector<std::shared_ptr<BadgeReader> > readers;
    std::vector<std::shared_ptr<Badge> > badges;
    std::vector<std::shared_ptr<Person> > people; // Stocke les objets Person pour éviter les fuites
    std::shared_ptr<Server> accessServer; // Stocke Server comme membre
    std::mt19937 randomGenerator;
    double localTime;

public:
    Scheduler();

    ~Scheduler() = default;

    void initializeReaders();

    void initializeBadges();

    void simulateRandomDay();

    void simulateRandomWeek();

    void simulateRandomAccessEvent();

    void simulateAccessEvent(const std::shared_ptr<Badge> &badge, const std::shared_ptr<BadgeReader> &reader);

    void addReader(const std::shared_ptr<BadgeReader> &reader);

    void addBadge(const std::shared_ptr<Badge> &badge);

    const std::vector<std::shared_ptr<BadgeReader> > &getReaders() const;

    const std::vector<std::shared_ptr<Badge> > &getBadges() const;
};
