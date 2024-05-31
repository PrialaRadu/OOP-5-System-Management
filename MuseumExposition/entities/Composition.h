//
// Created by Priala on 5/30/2024.
//

#ifndef SUBIECT_EXAMEN_3_OBJECT_H
#define SUBIECT_EXAMEN_3_OBJECT_H

#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Composition {
private:
    string author;
    string name;
    string category;
    int votes;
public:
    Composition(string author, string name, string category, int votes) : author(std::move(author)), name(std::move(name)),
        category(std::move(category)), votes(votes) {};
    Composition() = default;
    ~Composition() = default;

    string getAuthor() {
        return this->author;
    }
    string getName() {
        return this->name;
    }
    string getCategory() {
        return this->category;
    }
    int getVotes() {
        return this->votes;
    }

    bool operator==(const Composition& comp) const {
        return this->author == comp.name && this->name == comp.name && this->category == comp.category;
    }

    friend ostream& operator<<(ostream &os, Composition &comp){
        os << "Author: " << comp.getAuthor() << ", name: " << comp.getName() << ", category: " << comp.category
        << ", votes: " << comp.votes;
        return os;
    }
};

#endif //SUBIECT_EXAMEN_3_OBJECT_H
