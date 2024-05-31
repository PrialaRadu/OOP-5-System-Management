//
// Created by Priala on 5/30/2024.
//

#ifndef SUBIECT_EXAMEN_2_SERVICE_H
#define SUBIECT_EXAMEN_2_SERVICE_H

#include "../entities/Match.h"
#include "../repo/Repo.h"
#include <stdlib.h>
#include <algorithm>

class Service {
private:
    Repo &repo;
public:
    Service(Repo &repo) : repo(repo) {};
    ~Service() = default;

    void addTeams(set<string> &teams) {
        this->repo.addTeams(teams);
    }

    vector<Match> getMatches(){
        return repo.getMatches();
    }

    // 1.
    void addMatch(Match match) {
        this->repo.addMatch(match);
    }

    // 2.
    std::vector<std::pair<std::string, int>> returnSortedTable() {
        std::map<std::string, int> table = repo.getTable();
        std::vector<std::pair<std::string, int>> sortedTable(table.begin(), table.end());

        std::sort(sortedTable.begin(), sortedTable.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

        return sortedTable;
    }

    // 3.
    void simulateTourney() {
        this->repo.clear();

        set<string> teams = repo.getTeams();
        for (auto it1 = teams.begin(); it1 != teams.end(); ++it1) {
            auto it2 = it1;
            ++it2;
            for (; it2 != teams.end(); ++it2) {
                const string& team1 = *it1;
                const string& team2 = *it2;

                int goals1 = rand() % 5;
                int goals2 = rand() % 5;

                Match match(team1, goals1, team2, goals2);
                this->repo.addMatch(match);
            }
        }
    }

    vector<pair<string, int>> findWinners() {
        vector<pair<string, int>> winners;
        int maxPoints = 0;
        for (const auto &entry: this->repo.getTable()) {
            if (entry.second > maxPoints)
                maxPoints = entry.second;
        }
        for (const auto &entry: this->repo.getTable()) {
            if (entry.second == maxPoints)
                winners.emplace_back(entry);
        }
        return winners;
    }
};

#endif //SUBIECT_EXAMEN_2_SERVICE_H
