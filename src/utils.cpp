//
// Created by arman on 17/09/2025.
//
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "../include/utils.h"
#include <iostream>
using namespace std;

vector<string> split(const string &s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

vector<string> getPermissionsList(string path, string occupation) {
    ifstream file(path);
    string line;
    vector<string> permissions;

    if (!file.is_open()) {
        return permissions; // Retourne un vecteur vide si le fichier ne s'ouvre pas
    }

    // Lire la première ligne (en-tête) et l'ignorer
    getline(file, line);

    while (getline(file, line)) {
        vector<string> tokens = split(line, ',');
        if (tokens.size() >= 2 && tokens[0] == occupation) {
            for (int i = 1; i < tokens.size(); i++) {
                tokens[i].erase(remove(tokens[i].begin(), tokens[i].end(), '\"'), tokens[i].end());
                permissions.push_back(tokens[i]);
            }
            break;
        }
    }

    file.close();
    return permissions;
}