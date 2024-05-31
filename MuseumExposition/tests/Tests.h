//
// Created by Priala on 5/30/2024.
//

#ifndef SUBIECT_EXAMEN_3_TESTS_H
#define SUBIECT_EXAMEN_3_TESTS_H

#include "../entities/Composition.h"
#include "../repo/Repo.h"
#include "../service/Service.h"
#include <cassert>

void testEntity() {
    Composition comp("author1", "name1", "category1", 7);

    assert (comp.getAuthor() == "author1");
    assert (comp.getVotes() == 7);
}

void testRepo() {
    Repo repo;

    Composition comp1("author1", "name1", "category1", 7);
    Composition comp2("author2", "name2", "category2", 8);

    repo.addComposition(comp1, 0);
    repo.addComposition(comp2, 1);

    assert (repo.getCatalog().size() == 2);

    assert (repo.statisticsVotes()[0].first == "category2");
    assert (repo.statisticsVotes()[0].second == 8);
}

void testService() {
    Repo repo;
    Service service(repo);

    Composition comp1("author1", "name1", "category1", 7);
    Composition comp2("author2", "name2", "category2", 8);

    service.addComposition(comp1, 0);
    service.addComposition(comp2, 1);


    assert(service.returnCatalog().size() == 2);

    assert (service.statisticsVotes()[0].first == "category2");
    assert (service.statisticsVotes()[0].second == 8);

    assert (service.returnNumCompositionsOfCategoryFromAuthor("category1", "author1") == 1);
}

void testAll() {
    testEntity();
    testRepo();
    testService();

    cout << "All tests ran successfully! \n";
}

#endif //SUBIECT_EXAMEN_3_TESTS_H
