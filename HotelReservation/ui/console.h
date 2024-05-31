//
// Created by Priala on 5/30/2024.
//

#ifndef SUBIECT_EXAMEN_1_CONSOLE_H
#define SUBIECT_EXAMEN_1_CONSOLE_H

#include <iostream>
#include <stdexcept>
#include "../service/Service.h"
#include "../repository/Repo.h"

class UI {
private:
    Service &service;
public:
    explicit UI(Service& service) : service(service){};
    ~UI() = default;

    void printMenu() {
        cout << "MENU:\n";
        cout << "1. Rezervarea unei camere\n";
        cout << "2. Calculeaza checkout date\n";
        cout << "3. Cauta camere libere dupa data\n";
        cout << "0. Exit\n";
    }

    // b)
    void displaySortedReservations() {
        for (Reservation &res: service.returnSortedReservations())
            cout << res << endl;
    }

    // c)
    void displayAvailableRooms(int date) {
        for (Room &room: service.findAvailableRooms(date))
            cout << room << endl;
    }

    void runMenu() {
        int choice;
        do {
            printMenu();
            cin >> choice;
            switch (choice) {
                case 1: {
                    string type;
                    int checkInDate, duration;
                    cout << "Tipul camerei (single/double/apartment): ";
                    cin >> type;
                    cout << "Data check-in: ";
                    cin >> checkInDate;
                    cout << "Durata (numar de zile): ";
                    cin >> duration;
                    if (service.reserveRoom(type, checkInDate, duration))
                        cout << "Rezervare reusita.\n";
                    else
                        cout << "Rezervarea nu s-a putut efectua!";
                    break;
                }
                case 2:
                    displaySortedReservations();
                    break;
                case 3: {
                    int date;
                    cout << "Ziua: ";
                    cin >> date;
                    if (service.findAvailableRooms(date).size() == 0)
                        throw std::runtime_error("Nicio camera libera! ");
                    else
                        displayAvailableRooms(date);

                    break;
                }
                case 0:
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 0);
    }

};

#endif //SUBIECT_EXAMEN_1_CONSOLE_H
