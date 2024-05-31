//
// Created by Priala on 5/30/2024.
//

#ifndef SUBIECT_EXAMEN_4_SERVICE_H
#define SUBIECT_EXAMEN_4_SERVICE_H

#include "../repo/Repo.h"
#include <algorithm>

class Service {
private:
    Repo repo;
public:
    Service(Repo &repo) : repo(repo) {};
    ~Service() = default;

    int getRobotCap(){
        return this->repo.getRobotCap();
    }

    void setRobotCap(int value){
        this->repo.setRobotCap(value);
    }

    vector<Room> returnRooms(){
        return this->repo.getRooms();
    }

    void addRoom(Room &room) {
        this->repo.addRoom(room);
    }

    // 1.
    void removeRoom(Room &room) {
        this->repo.removeRoom(room);
    }

    // 2.
    void maximizeCleaning() {
        // sorteaza camerele dupa timpul de curatare
        vector<Room> sortedRooms = repo.getRooms();
        std::sort(sortedRooms.begin(), sortedRooms.end(), [](Room& a, Room& b) {
            return (a.getTime() * a.getMode() < b.getTime() * b.getMode());
        });
        this->repo.setRooms(sortedRooms);
    }

    // 3.
    vector<Room> findRoomsWithModeAndType(int mode, int time) {
        vector<Room> specificRooms;
        for (Room &room: this->repo.getRooms())
            if (mode == room.getMode() && time < room.getTime() * room.getMode())
                specificRooms.push_back(room);
        return specificRooms;
    }
};

#endif //SUBIECT_EXAMEN_4_SERVICE_H
