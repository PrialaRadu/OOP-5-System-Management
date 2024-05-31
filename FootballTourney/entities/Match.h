//
// Created by Priala on 5/30/2024.
//

#ifndef SUBIECT_EXAMEN_2_MATCH_H
#define SUBIECT_EXAMEN_2_MATCH_H

#include <iostream>

using namespace std;

class Match {
private:
    string team1, team2;
    int goals1, goals2;
public:
    Match() = default;

    Match(string team1, int goals1, string team2, int goals2) : team1(team1), goals1(goals1), team2(team2),
                                                                goals2(goals2) {};

    ~Match() = default;

    string getTeam1() {
        return this->team1;
    }

    string getTeam2() {
        return this->team2;
    }

    int getGoals1() {
        return this->goals1;
    }

    int getGoals2() {
        return this->goals2;
    }

    friend ostream& operator<<(ostream &os, Match &match) {
        os << "MATCH: " << match.getTeam1() << " vs " << match.getTeam2() << " = " << match.goals1 << " - " << match.goals2;
        return os;
    }
};

#endif //SUBIECT_EXAMEN_2_MATCH_H
