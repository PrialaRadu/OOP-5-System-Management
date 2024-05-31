//
// Created by Priala on 5/30/2024.
//

#ifndef SUBIECT_EXAMEN5_CONSOLE_H
#define SUBIECT_EXAMEN5_CONSOLE_H

#include "../service/Service.h"

class Console {
private:
    Service &service;
public:
    Console(Service &service) : service(service) {};

    ~Console() = default;

    void displayAllBacterias() {
        for (const auto& bacteria: service.returnAllBacterias())
            cout << bacteria << endl;
    }

    void displayBacteriasOfType(int type) {
        for (const auto& bacteria: service.returnBacteriasOfType(type))
            cout << bacteria << endl;
    }

    void displayBacteriasAfterUnitsOfTime(int units) {
        this->service.evolution(units);
        displayAllBacterias();
    }

    void displayAverageAgeAfterUnitsOfTime(int units) {
        cout << "Average age: " << this->service.returnAverageAgeAfterEvolution(units) << endl;
    }

    void printMenu() {
        cout << "MENU:\n";
        cout << "1. Display bacterias. \n";
        cout << "2. Display bacterias of type. \n";
        cout << "3. Display bacterias after x units of time. \n";
        cout << "4. Display average age after x units of time. \n";
        cout << "0. Exit. \n";
    }

    void menu() {
        printMenu();
        int choice = 0;
        cout << "Enter your choice: \n";
        cin >> choice;
        while (choice != 0) {
            switch (choice) {
                case 1:
                    displayAllBacterias();
                    break;
                case 2: {
                    int type;
                    cout << "Enter the type (0 or 1):\n";
                    cin >> type;
                    displayBacteriasOfType(type);
                    break;
                }
                case 3: {
                    int units;
                    cout << "Enter units of time: \n";
                    cin >> units;
                    displayBacteriasAfterUnitsOfTime(units);
                    break;
                }
                case 4: {
                    int units;
                    cout << "Enter units of time: \n";
                    cin >> units;
                    displayAverageAgeAfterUnitsOfTime(units);
                    break;
                }
                case 0:
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
                    break;
            }
            cout << "Enter your choice: \n";
            cin >> choice;
        }
    }


};

#endif //SUBIECT_EXAMEN5_CONSOLE_H
