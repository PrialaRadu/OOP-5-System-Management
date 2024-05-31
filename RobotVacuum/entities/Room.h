//
// Created by Priala on 5/30/2024.
//

#ifndef SUBIECT_EXAMEN_4_ROOM_H
#define SUBIECT_EXAMEN_4_ROOM_H

#include <iostream>
using namespace std;

class Room {
private:
    int id;
    int time;
    int mode; // {2, 5, 10}  adica unitati per min
public:
    Room(int id, int time, int mode) : id(id), time(time), mode(mode) {};
    ~Room() = default;

    int getId(){
        return this->id;
    }
    int getTime(){
        return this->time;
    }
    int getMode(){
        return this->mode;
    }

    bool operator==(const Room &other) const {
        return this->id == other.id;
    }

    friend ostream& operator<<(ostream &os, Room &room) {
        os << "id: " << room.getId() << ", time: " << room.getTime() << ", mode: " << room.getMode();
        return os;
    }
};

#endif //SUBIECT_EXAMEN_4_ROOM_H
