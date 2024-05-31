//
// Created by Priala on 5/30/2024.
//

#ifndef SUBIECT_EXAMEN_4_REPO_H
#define SUBIECT_EXAMEN_4_REPO_H

#include "../entities/Robot.h"
#include "../entities/Room.h"
#include <algorithm>

class Repo{
private:
    Robot robot;
    vector<Room> roomsToClean;
public:
    Repo() = default;
    ~Repo() = default;

    int getRobotCap(){
        return this->robot.getBattCap();
    }

    void setRobotCap(int value){
        this->robot.setBattCap(value);
    }

    vector<Room> getRooms() {
        return this->roomsToClean;
    }

    void setRooms(vector<Room> &newRooms) {
        this->roomsToClean = newRooms;
    }

    void addRoom(const Room &room) {
        this->roomsToClean.push_back(room);
    }

    // 1.
    void removeRoom(const Room &room) {
        auto it = std::find(roomsToClean.begin(), roomsToClean.end(), room);
        if (it != roomsToClean.end()) {
            roomsToClean.erase(it);
        }
    }
};

#endif //SUBIECT_EXAMEN_4_REPO_H
