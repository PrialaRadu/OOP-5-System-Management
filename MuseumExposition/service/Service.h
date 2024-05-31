//
// Created by Priala on 5/30/2024.
//

#ifndef SUBIECT_EXAMEN_3_SERVICE_H
#define SUBIECT_EXAMEN_3_SERVICE_H

#include "../repo/Repo.h"

class Service {
private:
    Repo &repo;
public:
    Service(Repo& repo) : repo(repo) {};
    ~Service() = default;

    map<int, Composition> returnCatalog() {
        return this->repo.getCatalog();
    }

    // 1.
    void addComposition(Composition &comp, int index) {
        this->repo.addComposition(comp, index);
    }

    // 2.
    vector<pair<string, int>> statisticsVotes() {
        set<string> categories;
        map<string, int> statistics;

        // gaseste toate categoriile
        for (auto &entry : repo.getCatalog()) {
            Composition &comp = entry.second;
            categories.insert(comp.getCategory());
        }

        // afla nr de voturi pt fiecare categorie
        for (auto &entry : repo.getCatalog()) {
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

    // 3.
    int returnNumCompositionsOfCategoryFromAuthor(string category, string author) {
        int totalCompositions = 0;
        for (auto& entry: repo.getCatalog())
            if (entry.second.getCategory() == category && entry.second.getAuthor() == author)
                totalCompositions++;
        return totalCompositions;
    }
};

#endif //SUBIECT_EXAMEN_3_SERVICE_H
