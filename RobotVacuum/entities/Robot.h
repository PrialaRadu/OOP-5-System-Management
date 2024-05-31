#ifndef SUBIECT_EXAMEN_4_ROBOT_H
#define SUBIECT_EXAMEN_4_ROBOT_H

#include "Room.h"
#include <vector>
using namespace std;

class Robot {
private:
    int battCap;
public:
    Robot() {
        this->battCap = 100;
    }
    ~Robot() = default;

    int getBattCap(){
        return this->battCap;
    }

    void setBattCap(int newBattCap) {
        this->battCap = newBattCap;
    }
};

#endif //SUBIECT_EXAMEN_4_ROBOT_H
