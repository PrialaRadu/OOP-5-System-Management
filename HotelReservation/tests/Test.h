//
// Created by Priala on 5/30/2024.
//

#ifndef SUBIECT_EXAMEN_1_TEST_H
#define SUBIECT_EXAMEN_1_TEST_H

#include "../entities/Room.h"
#include "../entities/Reservation.h"
#include <cassert>
#include <iostream>

void testRoom() {
    Room room1(1, "single", 200);
    Room room2(2, "double", 350);

    assert (room1.getId() == 1);
    assert (room2.getType() == "double");
    assert (room2.getPrice() == 350);
}

void testReservation() {
    Reservation reservation(1, 20, 4);

    assert (reservation.getRoomId() == 1);
    assert (reservation.getCheckInDate() == 20);
    assert (reservation.getDuration() == 4);
    assert (reservation.getCheckOutDate() == 23);
}

void testRepo (){
    Repository repo;

    assert (repo.getRooms().size() == 14);
    assert (repo.getReservations().empty());
}

void testService() {
    Repository repo;
    Service service(repo);

    assert (service.reserveRoom("apartment", 1, 30));
    assert (service.reserveRoom("single", 6, 4));
    assert (service.reserveRoom("double", 6, 3));

    assert (service.findAvailableRooms(7).size() == 11);
}

void testAll() {
    testRoom();
    testReservation();
    testRepo();
    testService();
    std::cout << "All tests ran successfully! \n";
}

#endif //SUBIECT_EXAMEN_1_TEST_H
