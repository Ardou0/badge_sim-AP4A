//
// Created by Walle on 17/09/2025.
//
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include "../include/Server.h"
#include "../include/Badge.h"
#include "../include/BadgeReader.h"
using namespace std;

Server::Server() {
    // Récupérer l'heure actuelle
    time_t now = time(nullptr);
    tm *localTime = localtime(&now);

    // Formater la date en mm-dd-yyyy
    ostringstream oss;
    oss << "../logs/" << put_time(localTime, "%m-%d-%Y") << ".log";
    this->logFilePath = oss.str();
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

void Server::logEvent(const string& eventType, const string& event) {
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
        << "] ";

    // Construire la ligne de log
    string logLine = oss.str() + eventType + " : " + event + " ;\n";

    // Ouvrir le fichier en mode append (création si inexistant)
    ofstream logFile(this->logFilePath, ios_base::app);
    if (logFile.is_open()) {
        logFile << logLine;
        logFile.close();
    } else {
        // Gérer l'erreur d'ouverture du fichier
        cerr << "Erreur : Impossible d'ouvrir le fichier de log : "
             << this->logFilePath << endl;
    }
}


bool Server::validateAccessRights(const BadgeReader& reader, const Badge& badge) {
    // 1. Vérifier si le lieu du lecteur est dans les droits du badge
    std::vector<std::string> badgeRights = badge.getAccessRights();
    std::string readerLocation = reader.getLocation();

    if (std::find(badgeRights.begin(), badgeRights.end(), readerLocation) == badgeRights.end()) {
        return false; // Le lieu n'est pas autorisé par le badge
    }

    // 2. Vérifier que les droits du badge sont un sous-ensemble des droits du statut
    std::string occupation = badge.getOwner()->getOccupation();
    std::vector<std::string> configRights;

    // Parcourir this->config pour trouver les droits associés à l'occupation
    for (const auto& row : this->config) {
        if (row[0] == occupation) {
            // Supposons que les droits commencent à partir de l'index 1
            for (size_t i = 1; i < row.size(); ++i) {
                configRights.push_back(row[i]);
            }
            break;
        }
    }

    // Vérifier que chaque droit du badge est dans configRights
    for (const auto& right : badgeRights) {
        if (std::find(configRights.begin(), configRights.end(), right) == configRights.end()) {
            return false; // Le badge a un droit non autorisé par le statut
        }
    }

    return true; // Toutes les vérifications sont passées
}
