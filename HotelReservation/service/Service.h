//
// Created by Priala on 5/21/2024.
//

#ifndef SUBIECT_EXAMEN_1_SERVICE_H
#define SUBIECT_EXAMEN_1_SERVICE_H

#include "../repository/Repo.h"
#include <string>

class Service {
private:
    Repository &repo;
public:
    explicit Service(Repository &repo) : repo(repo) {};
    ~Service() = default;

    // a
    bool reserveRoom(const string& type, int checkinDate, int duration) {
        return this->repo.reserveRoom(type, checkinDate, duration);
    }

    // b)
    vector<Reservation> returnSortedReservations() {
        vector<Reservation> sortedReservation = repo.getReservations();
        std::sort(sortedReservation.begin(), sortedReservation.end(), [](const Reservation& a, const Reservation& b) {
            return a.getCheckOutDate() < b.getCheckOutDate();
        });
        return sortedReservation;
    }

    // c)
    vector<Room> findAvailableRooms(int date) {
        vector<Room> availableRooms;
        for (Room room: repo.getRooms())
            if (room.getAvailableDates()[date])
                availableRooms.push_back(room);

        vector<Room> sortedRooms = availableRooms;
        std::sort(sortedRooms.begin(), sortedRooms.end(), [](Room& a, Room& b) {
            return a.getPrice() < b.getPrice();
        });
        return sortedRooms;
    }

};

#endif //SUBIECT_EXAMEN_1_SERVICE_H
