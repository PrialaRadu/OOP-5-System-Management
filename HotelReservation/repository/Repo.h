//
// Created by Priala on 5/30/2024.
//

#ifndef SUBIECT_EXAMEN_1_REPO_H
#define SUBIECT_EXAMEN_1_REPO_H

#include <vector>
#include <algorithm>
#include "../entities/Room.h"
#include "../entities/Reservation.h"

class Repository {
private:
    vector<Room> rooms;
    vector<Reservation> reservations;

public:
    // Constructor, Deconstructor
    Repository() {
        for (int i = 0; i < 5; ++i) rooms.emplace_back(i + 1, "single", 200);
        for (int i = 5; i < 12; ++i) rooms.emplace_back(i + 1, "double", 350);
        for (int i = 12; i < 14; ++i) rooms.emplace_back(i + 1, "apartment", 500);
    }
    ~Repository() = default;

    void saveReservation(const Reservation &res) {
        this->reservations.emplace_back(res);
        saveReservations();
    }

    // Getters
    vector<Reservation> getReservations() {
        return reservations;
    }

    [[nodiscard]] const vector<Room>& getRooms() const{
        return rooms;
    }

    // a.
    bool reserveRoom(const string& type, int checkinDate, int duration) {
        for (Room &room : this->rooms)
            if (room.getType() == type) {
                bool isAvailable = true;
                for (int date = checkinDate; date < checkinDate + duration; date++) {
                    if (!room.getAvailableDates()[date]) {
                        isAvailable = false;
                        break;
                    }
                }
                if (isAvailable) {
                    saveReservation(Reservation(room.getId(), checkinDate, duration));
                    room.reserveDays(checkinDate, checkinDate + duration);
                    return true;
                }
            }
        return false;
    }

    void saveReservations() {
        ofstream outFile(R"(C:\\Users\\Priala\\CLionProjects\\subiect_hotel\\data\\reservations)");
        for (Reservation &res : reservations) {
            outFile << res.getRoomId() << " " << res.getCheckInDate() << " " << res.getDuration() << " " << res.getCheckOutDate() << "\n";
        }
        outFile.close();
    }

    void loadReservations() {
        ifstream inFile(R"(C:\\Users\\Priala\\CLionProjects\\subiect_hotel\\data\\reservations)");
        if (!inFile.is_open()) return;
        int roomId, checkInDate, duration, checkOutDate;
        while (inFile >> roomId >> checkInDate >> duration >> checkOutDate) {
            reservations.emplace_back(roomId, checkInDate, duration);
        }
        inFile.close();
    }
};

#endif //SUBIECT_EXAMEN_1_REPO_H
