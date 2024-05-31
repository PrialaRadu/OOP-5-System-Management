//
// Created by Priala on 5/30/2024.
//

#ifndef SUBIECT_EXAMEN_3_CONSOLE_H
#define SUBIECT_EXAMEN_3_CONSOLE_H

#include "../service/Service.h"
#include <iostream>

class Console {
private:
    Service &service;
public:
    Console(Service &service) : service(service) {};

    ~Console() = default;

    // 1.
    void addComposition() {
        string author, name, category;
        int votes, index;
        cout << "Enter author name: ";
        cin >> author;
        cout << "Enter composition name: ";
        cin >> name;
        cout << "Enter category: ";
        cin >> category;
        cout << "Enter number of votes: ";
        cin >> votes;
        cout << "Enter index: ";
        cin >> index;

        Composition comp(author, name, category, votes);
        this->service.addComposition(comp, index);
    }

    // 2.
    void displayStatisticsVotes() {
        cout << "Number of votes: \n";
        for (auto &elem: this->service.statisticsVotes())
            cout << elem.first << ": " << elem.second << endl;
    }

    // 3.
    void displayNumCompositionsOfCategoryFromAuthor(){
        string category, author;
        cout << "Category: ";
        cin >> category;
        cout << "Author name: ";
        cin >> author;
        cout << "Number of compositions: " << this->service.returnNumCompositionsOfCategoryFromAuthor(category, author);
    }

    void printCatalog() {
        for (auto &entry: this->service.returnCatalog())
            cout << entry.first << ": " << entry.second << endl;
    }

    void printMenu() {
        cout << "MENU: \n";
        cout << "1. Add composition. \n";
        cout << "2. Display votes statistics per category. \n";
        cout << "3. Find the number of compositions for a specified author and category\n";
    }

    int menu() {
        printMenu();
        int choice;
        cout << "Enter your choice: \n";
        cin >> choice;

        while (choice != 0) {
            switch (choice) {
                case 1:
                    addComposition();
                    printCatalog();
                    break;
                case 2:
                    displayStatisticsVotes();
                    break;
                case 3:
                    displayNumCompositionsOfCategoryFromAuthor();
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice. \n";
                    break;
            }

            if (choice == 0) {
                break;
            }

            cout << "Enter your choice: \n";
            cin >> choice;
        }

        return 0;
    }
};

#endif //SUBIECT_EXAMEN_3_CONSOLE_H
