//
// Created by Priala on 5/30/2024.
//

#ifndef SUBIECT_EXAMEN_4_CONSOLE_H
#define SUBIECT_EXAMEN_4_CONSOLE_H

#include <iostream>
using namespace std;
#include "../service/Service.h"

class Console {
private:
    Service &service;
public:
    Console(Service &service) : service(service) {};
    ~Console() = default;

//    void addRooms() {
//        int num;
//        cout << "Enter the number of rooms: ";
//        cin >> num;
//
//        int id, time, mode;
//        while (num){
//            cout << "id: ";
//            cin >> id;
//            cout << "time: ";
//            cin >> time;
//            cout << "mode (2, 5, 10): ";
//            cin >> mode;
//            Room room(id, time, mode);
//            this->service.addRoom(room);
//            num--;
//        }
//    }

    void printRooms() {
        for (Room &room: this->service.returnRooms())
            cout << room << endl;
    }

    // 1.
    void removeRoom() {
        int id, time, mode;
        string modeName;
        cout << "Enter room id: \n";
        cin >> id;
        cout << "Time: ";
        cin >> time;
        cout << "Mode (rapid, mediu, minutios): ";
        cin >> modeName;

        if (modeName == "rapid" ) mode = 2;
        if (modeName == "mediu") mode = 5;
        if (modeName == "minutions") mode = 10;

        Room room(id, time, mode);
        this->service.removeRoom(room);
    }

    // 2.
    void maximizeCleaning(){
        this->service.maximizeCleaning();
        for (Room &room: this->service.returnRooms()){
            int battery = this->service.getRobotCap();
            if (battery - room.getTime() * room.getMode() <= 10){
                cout << "Robotul se intoarce la statie! " << endl;
                break;
            }
            else {
                cout << room << endl;
                battery = battery - (room.getTime() * room.getMode());
                this->service.setRobotCap(battery);
            }
        }
    }

    // 3.
    void findRoomsWithModeAndTime() {
        int time, mode;
        string modeName;
        cout << "Time: ";
        cin >> time;
        cout << "Mode (rapid, mediu, minutios): ";
        cin >> modeName;

        if (modeName == "rapid" ) mode = 2;
        if (modeName == "mediu") mode = 5;
        if (modeName == "minutions") mode = 10;

        vector<Room> specifiedRooms = this->service.findRoomsWithModeAndType(mode, time);
        for (Room &room: specifiedRooms)
            cout << room << endl;
    }

    void printMenu(){
        cout << "MENU: \n";
        cout << "1. Remove room. \n";
        cout << "2. Maximize room cleaning. \n";
        cout << "3. Find rooms with specified mode and type. \n";
    }
    void menu(){
        printMenu();
        int choice = 0;
        do{
            cout << "Enter your choice: \n";
            cin >> choice;
            switch (choice){
                case (1):
                    removeRoom();
                    printRooms();
                    break;
                case (2):
                    maximizeCleaning();
                    break;
                case (3):
                    findRoomsWithModeAndTime();
                    break;
                default:
                    return;
            }
        }while(choice != 0);
    }
};

#endif //SUBIECT_EXAMEN_4_CONSOLE_H
