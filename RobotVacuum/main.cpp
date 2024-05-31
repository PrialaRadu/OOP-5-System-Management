#include <iostream>
#include "repo/Repo.h"
#include "service/Service.h"
#include "ui/Console.h"
#include "tests/Tests.h"

int main() {
    testAll();

    Repo repo;
    repo.addRoom(Room(1, 4, 2));
    repo.addRoom(Room(2, 2, 10));
    repo.addRoom(Room(3, 6, 10));
    repo.addRoom(Room(4, 4, 5));
    repo.addRoom(Room(5, 3, 2));
    repo.addRoom(Room(6, 14, 5));

    Service service(repo);
    Console console(service);

    console.menu();
    return 0;
}
