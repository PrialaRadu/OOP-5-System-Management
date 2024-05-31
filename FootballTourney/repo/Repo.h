//
// Created by Priala on 5/30/2024.
//

#ifndef SUBIECT_EXAMEN_2_REPO_H
#define SUBIECT_EXAMEN_2_REPO_H

#include <vector>
#include <map>
#include <set>

using namespace std;

#include "../entities/Match.h"

class Repo {
private:
    vector<Match> matches;
    map<string, int> table;
public:
    Repo(int numTeams) {
        matches.resize((numTeams - 1) * (numTeams - 1));    // nrMeciuri = (nrEchipe - 1)^2
    }

    ~Repo() = default;

    void addTeams(set<string> &teams) {
        for (const string &team: teams)
            table[team] = 0;
    }

    set<string> getTeams() {
        set<string> teams;
        for (auto& entry : table) {
            teams.insert(entry.first);
        }
        return teams;
    }

    vector<Match> getMatches(){
        return this->matches;
    }

    // reset all matches and table
    void clear() {
        this->matches.clear();
        for (auto elem: this->table)
            elem.second = 0;
    }

    // 1.
    void addMatch(Match &match) {
        matches.push_back(match);
        if (match.getGoals1() == match.getGoals2()) {
            table[match.getTeam1()] += 1;
            table[match.getTeam2()] += 1;
        }
        if (match.getGoals1() > match.getGoals2()) {
            table[match.getTeam1()] += 3;
            table[match.getTeam2()] += 0;
        } else {
            table[match.getTeam1()] += 0;
            table[match.getTeam2()] += 3;
        }
    }

    // 2.
    map<string, int> getTable() {
        return this->table;
    }
};

#endif //SUBIECT_EXAMEN_2_REPO_H
