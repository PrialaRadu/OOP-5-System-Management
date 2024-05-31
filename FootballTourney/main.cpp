#include <iostream>
#include "repo/Repo.h"
#include "service/Service.h"
#include "ui/Console.h"
#include "tests/Tests.h"

int main() {
    testAll();

    Repo repo(3);
    Service service(repo);
    Console console(service);

    console.menu();
    return 0;
}
