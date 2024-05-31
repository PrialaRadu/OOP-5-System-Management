//
// Created by Priala on 5/30/2024.
//

#ifndef SUBIECT_EXAMEN_4_TESTS_H
#define SUBIECT_EXAMEN_4_TESTS_H

#include "../entities/Robot.h"
#include "../entities/Room.h"
#include "../repo/Repo.h"
#include "../service/Service.h"
#include <cassert>

void testEntities(){
    Robot robot;
    Room room(1, 7, 2);

    assert (robot.getBattCap() == 100);

    assert (room.getId() == 1);
    assert (room.getTime() == 7);
    assert (room.getMode() == 2);
}

void testRepo() {
    Repo repo;

    Room room1(1, 7, 2);
    Room room2(2, 6, 5);

    repo.addRoom(room1);
    repo.addRoom(room2);

    assert (repo.getRooms().size() == 2);

    repo.removeRoom(room2);
    repo.removeRoom(room1);

    assert (repo.getRooms().empty());
}

void testService() {
    Repo repo;
    Service service(repo);

    Room room1(1, 7, 2);
    Room room2(2, 6, 5);
    Room room3(3, 1, 2);

    service.addRoom(room1);
    service.addRoom(room2);
    service.addRoom(room3);

    assert (service.returnRooms().size() == 3);

    assert (service.findRoomsWithModeAndType(2, 10)[0] == room1);
}

void testAll() {
    testEntities();
    testRepo();
    testService();
    cout << "All tests ran successfully! \n";
}

#endif //SUBIECT_EXAMEN_4_TESTS_H
