//
// Created by Priala on 5/30/2024.
//

#ifndef SUBIECT_EXAMEN5_SERVICE_H
#define SUBIECT_EXAMEN5_SERVICE_H

#include "../repo/Repo.h"
#include "../entities/Bacteria.h"
#include <vector>
#include <iostream>

using namespace std;

class Service {
private:
    Repo &repo;
public:
    Service(Repo &repo) : repo(repo) {};

    ~Service() = default;

    vector<Bacteria> returnAllBacterias() {
        return repo.getBacterias();
    }

    vector<Bacteria> returnBacteriasOfType(int type) {
        vector<Bacteria> bacteriasOfType;
        for (Bacteria bacteria: repo.getBacterias())
            if (bacteria.getType() == type)
                bacteriasOfType.push_back(bacteria);
        return bacteriasOfType;
    }

    vector<Bacteria> evolution(int units) {
        int current = 1;
        while (current <= units) {
            for (Bacteria &bacteria: repo.getBacterias()) {
                if (bacteria.getType() == 1) {
                    repo.addBacteria(Bacteria(bacteria.getName(), 0, 1));
                    repo.addBacteria(Bacteria(bacteria.getName(), 0, 1));
                    repo.removeBacteria(bacteria);
                }
                // type = 2
                else {
                    if (current % 3 == 0)
                        repo.addBacteria(Bacteria(bacteria.getName(), 0, 0));
                }
            }
            repo.increaseAge();
            current++;
        }
        return repo.getBacterias();
    }

    double returnAverageAgeAfterEvolution(int units) {
        evolution(units);
        int sumAge = 0;
        int count = repo.getBacterias().size();
        for (Bacteria bacteria: repo.getBacterias())
            sumAge += bacteria.getAge();
        return static_cast<double>(sumAge) / count;
    }
};

#endif //SUBIECT_EXAMEN5_SERVICE_H
