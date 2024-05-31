//
// Created by Priala on 5/30/2024.
//

#ifndef SUBIECT_EXAMEN_3_REPO_H
#define SUBIECT_EXAMEN_3_REPO_H

#include "../entities/Composition.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

class Repo {
private:
    map<int, Composition> catalog;
    int maxSize;

public:
    Repo(int size = 10) : maxSize(size) {}

    ~Repo() = default;

    map<int, Composition> getCatalog() {
        return catalog;
    }

    // 1.
    void addComposition(Composition &comp, int index) {
        if (index < 0 || index >= maxSize) {
            cout << "Index incorect! " << endl;
            return;
        }

        for (const auto &elem : catalog) {
            if (elem.second == comp) {
                cout << "Compozitia se afla deja in catalog! " << endl;
                return;
            }
        }

        catalog[index] = comp;
    }

    // 2.
    vector<pair<string, int>> statisticsVotes() {
        set<string> categories;
        map<string, int> statistics;

        // gaseste toate categoriile
        for (auto &entry : catalog) {
            Composition &comp = entry.second;
            categories.insert(comp.getCategory());
        }

        // afla nr de voturi pt fiecare categorie
        for (auto &entry : catalog) {
            Composition &comp = entry.second;
            statistics[comp.getCategory()] += comp.getVotes();
        }

        // sorteaza lista cu voturi
        vector<pair<string, int>> sortedStatistics(statistics.begin(), statistics.end());
        sort(sortedStatistics.begin(), sortedStatistics.end(), [](const auto &a, const auto &b) {
            return a.second > b.second;
        });

        return sortedStatistics;
    }
};

#endif //SUBIECT_EXAMEN_3_REPO_H
