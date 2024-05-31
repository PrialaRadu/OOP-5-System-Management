#include <iostream>
#include "entities/Bacteria.h"
#include "repo/Repo.h"
#include "service/Service.h"
#include "console/console.h"

int main() {
    Repo repo;
    Service service(repo);
    Console console(service);
    repo.addBacteria(Bacteria("a", 2, 1));
    repo.addBacteria(Bacteria("b", 3, 0));
    repo.addBacteria(Bacteria("c", 7, 0));

    console.menu();
    return 0;
}
