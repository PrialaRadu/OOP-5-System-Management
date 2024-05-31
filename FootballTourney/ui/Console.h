//
// Created by Priala on 5/30/2024.
//

#ifndef SUBIECT_EXAMEN_2_CONSOLE_H
#define SUBIECT_EXAMEN_2_CONSOLE_H

#include <iostream>
#include <stdexcept>
#include "../service/Service.h"

class Console {
private:
    Service &service;
public:
    Console(Service &service) : service(service) {};

    ~Console() = default;

    void readTeams() {
        int num;
        string team;
        cout << "Enter the number of teams: \n";
        cin >> num;
        set<string> teams;
        cout << "Enter all teams: \n";
        while (num) {
            cin >> team;
            teams.insert(team);
            num--;
        }
        this->service.addTeams(teams);
    }

    // 1.
    void addMatch() {
        string team1, team2;
        int goals1, goals2;
        cout << "Team1: ";
        cin >> team1;
        cout << "Team2: ";
        cin >> team2;
        cout << "Goals1: ";
        cin >> goals1;
        cout << "Goals2: ";
        cin >> goals2;

        if (team1 == team2)
            throw std::invalid_argument("Error: Same team!");
        if (goals1 < 0 || goals2 < 0)
            throw std::invalid_argument("Error: Goals should be positive numbers!");

        this->service.addMatch(Match(team1, goals1, team2, goals2));
        cout << "Match added.";
    }

    // 2.
    void displayTable() {
        for (const auto &entry: this->service.returnSortedTable()) {
            std::cout << entry.first << ": " << entry.second << std::endl;
        }
    }

    // 3.
    void simulateTourney() {
        this->service.simulateTourney();
        for (Match &match: this->service.getMatches())
            cout << match << endl;
        displayTable();
        cout << "Winner/Winners: \n";
        for (const auto& entry: this->service.findWinners())
            cout << entry.first << ": " << entry.second << endl;
    }

    void printMenu() {
        cout << "MENU: \n";
        cout << "1. Add match. \n";
        cout << "2. Display table tourney. \n";
        cout << "3. Simulate tourney. \n";
        cout << "0. Exit. \n";
    }

    void menu() {
        readTeams();
        printMenu();

        int choice;
        do {
            printMenu();
            cin >> choice;
            switch (choice) {
                case (1):
                    addMatch();
                    break;
                case (2):
                    displayTable();
                    break;
                case (3):
                    simulateTourney();
                    break;
                default:
                    break;
            }
        } while (choice != 0);
    }
};

#endif //SUBIECT_EXAMEN_2_CONSOLE_H
