//
// Created by Priala on 5/30/2024.
//

#ifndef SUBIECT_EXAMEN_1_RESERVATION_H
#define SUBIECT_EXAMEN_1_RESERVATION_H

class Reservation {
private:
    int roomId;
    int checkInDate;
    int duration;
    int checkOutDate;
public:
    Reservation(int roomId, int checkInDate, int duration)
            : roomId(roomId), checkInDate(checkInDate), duration(duration) {
        checkOutDate = checkInDate + duration - 1;
    }
    ~Reservation() = default;

    // Getters
    int getRoomId() const {
        return this->roomId;
    }
    int getCheckInDate() {
        return this->checkInDate;
    }
    int getDuration() {
        return this->duration;
    }
    int getCheckOutDate() const {
        return this->checkOutDate;
    }

    friend ostream& operator<<(ostream& os, const Reservation &res) {
        os << "Room ID: " << res.roomId << ", Checkin date: " << res.checkInDate << ", Checkout date: " << res.checkOutDate;
        return os;
    }
};

#endif //SUBIECT_EXAMEN_1_RESERVATION_H
