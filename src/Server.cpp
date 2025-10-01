//
// Created by Walle on 17/09/2025.
//
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <ctime>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include "../include/Server.h"
#include "../include/Badge.h"
#include "../include/BadgeReader.h"
#include <filesystem>
namespace fs = std::filesystem;
using namespace std;

Server::Server(double &timeReference) : localTime(timeReference) {
    // Récupérer l'heure actuelle
    time_t now = time(nullptr);
    tm *localTime = localtime(&now);
    if (localTime == nullptr) {
        throw runtime_error("Failed to get local time");
    }

    // Formater la date en mm-dd-yyyy
    ostringstream oss;
    oss << "../logs/" << put_time(localTime, "%m-%d-%Y") << ".log";
    this->logFilePath = oss.str();

    // Vérifiez que le chemin est valide avant d'utiliser std::filesystem
    if (this->logFilePath.empty()) {
        throw runtime_error("Log file path is empty");
    }
    // Utilisez un chemin absolu pour éviter les problèmes
    fs::path logPath(this->logFilePath);
    fs::path logDir = logPath.parent_path();

    // Vérifiez que le chemin parent est valide
    if (!logDir.empty()) {
        // Créez le dossier si nécessaire
        if (!fs::exists(logDir)) {
            fs::create_directories(logDir);
        }
    }

    // Convertissez en chemin absolu
    this->logFilePath = fs::absolute(logPath).string();

    // Chargez la configuration
    this->loadConfig();
}


void Server::loadConfig() {
    string filename = "../config/permissions.csv";
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Unable to open : " + filename);
    }

    string line;
    bool isFirstLine = true;

    while (getline(file, line)) {
        if (isFirstLine) {
            isFirstLine = false;
            continue;
        }

        vector<string> row;
        stringstream ss(line);
        string cell;

        while (std::getline(ss, cell, ',')) {
            row.push_back(cell);
        }

        if (!row.empty()) {
            this->config.push_back(row);
        }
    }

    file.close();
}

std::string Server::formatTimeDouble(double timeDouble) {
    int hours = static_cast<int>(timeDouble);
    double fractionalPart = timeDouble - hours;
    int minutes = static_cast<int>(fractionalPart * 60);

    std::ostringstream oss;
    oss << hours << "h" << std::setw(2) << std::setfill('0') << minutes;
    return oss.str();
}

void Server::logEvent(const string &eventType, const string &event) {
    // Récupérer l'heure actuelle
    auto now = chrono::system_clock::now();
    auto now_time = chrono::system_clock::to_time_t(now);
    auto now_ms = chrono::duration_cast<chrono::milliseconds>(
                      now.time_since_epoch()) % 1000;

    // Formater l'heure en hh-mm-ss-ms
    tm time_info = *localtime(&now_time);
    ostringstream oss;
    oss << put_time(&time_info, "[%H-%M-%S")
            << "-" << setw(3) << setfill('0') << now_ms.count()
            << " - " << this->formatTimeDouble(this->localTime) << "] ";

    // Construire la ligne de log
    string logLine = oss.str() + eventType + " : " + event + ";\n";

    // Ouvrir le fichier en mode append (création si inexistant)
    ofstream logFile(this->logFilePath, ios_base::app);
    if (logFile.is_open()) {
        logFile << logLine;
        logFile.close();
    } else {
        cerr << "Error : Cannot open log file : "
                << this->logFilePath << endl;
    }
}


bool Server::validateAccessRights(const BadgeReader &reader, const Badge &badge) {
    // 1. Vérifier si le lieu du lecteur est dans les droits du badge
    std::vector<std::string> badgeRights = badge.getAccessRights();
    std::string readerLocation = reader.getLocation();

    if ((this->localTime > 18 || this->localTime < 8) && badge.getOwner()->getOccupation() != "securityStaff") {
        this->logEvent(
            "Warning",
            "Access is not authorized for " + readerLocation + " by the server (ref(time, access rights, " + badge.
            getOwner()->getName() + " is only " + badge.getOwner()->getOccupation() + ")) Open from 8 a.m. to 6 p.m");
        return false; // L'accès n'est pas autorisé par le serveur à cette heure de la journée sauf pour la sécurité
    }

    if (std::find(badgeRights.begin(), badgeRights.end(), readerLocation) == badgeRights.end()) {
        this->logEvent(
            "Warning",
            "Access is not authorized for " + readerLocation + " by the badge (ref(badge, access rights, " + badge.
            getOwner()->getName() + "))");
        return false; // Le lieu n'est pas autorisé par le badge
    }

    // 2. Vérifier que les droits du badge sont un sous-ensemble des droits du statut
    std::string occupation = badge.getOwner()->getOccupation();
    std::vector<std::string> configRights;

    // Parcourir this->config pour trouver les droits associés à l'occupation
    for (const auto &row: this->config) {
        if (row[0] == occupation || (row[0] == ("E" + occupation) && badge.getOwner()->getHasExecption())) {
            for (size_t i = 0; i < row.size(); ++i) {
                configRights.push_back(row[i]);
            }
        }
    }

    // Vérifier que chaque droit du badge est dans configRights
    for (const auto &right: badgeRights) {
        if (std::find(configRights.begin(), configRights.end(), right) == configRights.end()) {
            this->logEvent(
                "Warning",
                "Access is not authorized for " + readerLocation + " by the owner occupation (ref(owner, occupation, " +
                badge.getOwner()->
                getName() + " " + badge.getOwner()->getOccupation() + "))");
            return false; // Le badge a un droit non autorisé par le statut
        }
    }

    this->logEvent(
        "Access",
        badge.getOwner()->getName() + " (" + badge.getOwner()->getOccupation() + ") has accessed " + reader.
        getLocation());
    return true; // Toutes les vérifications sont passées
}
