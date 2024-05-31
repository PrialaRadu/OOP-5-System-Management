//
// Created by Priala on 5/30/2024.
//

#ifndef SUBIECT_EXAMEN5_BACTERIA_H
#define SUBIECT_EXAMEN5_BACTERIA_H

#include <iostream>
#include <string>
using namespace std;

class Bacteria {
private:
    string name;
    int age;
    int type;   // {1, 2}
public:
    Bacteria() = default;
    Bacteria(string name, int age, int type) : name(name), age(age), type(type) {};
    ~Bacteria() = default;

    string getName() {
        return this->name;
    }
    int getAge() {
        return this->age;
    }
    int getType() {
        return this->type;
    }

    void increaseAge() {
        this->age++;
    }

    bool operator==(const Bacteria& other) const {
        return name == other.name && age == other.age && type == other.type;
    }

    friend ostream& operator<<(ostream& os, const Bacteria &bacteria) {
        os << "Name: " << bacteria.name << ", age: " << bacteria.age << ", type: " << bacteria.type;
        return os;
    }
};

#endif //SUBIECT_EXAMEN5_BACTERIA_H
