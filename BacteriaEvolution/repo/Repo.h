//
// Created by Priala on 5/30/2024.
//

#ifndef SUBIECT_EXAMEN5_REPO_H
#define SUBIECT_EXAMEN5_REPO_H

#include <vector>
#include <algorithm>
using namespace std;
#include "../entities/Bacteria.h"

class Repo {
private:
    vector<Bacteria> bacterias;
public:
    Repo() = default;
    ~Repo() = default;

    vector<Bacteria> getBacterias() {
        return this->bacterias;
    }

    // Methods
    void addBacteria(const Bacteria& bacteria) {
        this->bacterias.push_back(bacteria);
    }
    void removeBacteria(const Bacteria& bacteria) {
        auto it = std::find(bacterias.begin(), bacterias.end(), bacteria);
        if (it != bacterias.end()) {
            bacterias.erase(it);
        }
    }
    void increaseAge() {
        for (Bacteria &bacteria: bacterias)
            if (bacteria.getType() == 0)
                bacteria.increaseAge();
    }
};

#endif //SUBIECT_EXAMEN5_REPO_H
