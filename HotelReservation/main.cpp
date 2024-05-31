#include <iostream>
#include "entities/Room.h"
#include "repository/Repo.h"
#include "service/Service.h"
#include "ui/console.h"
#include "tests/Test.h"

int main() {
    testAll();

    Repository hotel;
    Service service(hotel);
    UI ui(service);

    ui.runMenu();

    return 0;
}