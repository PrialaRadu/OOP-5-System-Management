//
// Created by Priala on 5/30/2024.
//

#ifndef SUBIECT_EXAMEN_2_TESTS_H
#define SUBIECT_EXAMEN_2_TESTS_H

#include <cassert>
#include "../entities/Match.h"
#include "../repo/Repo.h"
#include "../service/Service.h"

void testEntity() {
    Match m1("team1", 1, "team2", 0);

    assert (m1.getTeam1() == "team1");
    assert (m1.getTeam2() == "team2");
    assert (m1.getGoals1() == 1);
    assert (m1.getGoals2() == 0);
}

void testRepo() {
    Repo repo(3);
    set<string> teams = {"t1", "t2", "t3"};
    repo.addTeams(teams);

    Match m1("t1", 1, "t2", 0);
    Match m2("t1", 1, "t3", 1);
    Match m3("t3", 1, "t2", 2);

    repo.addMatch(m1);
    repo.addMatch(m2);
    repo.addMatch(m3);

    assert (repo.getTable().size() == 3);
    repo.clear();
    assert (repo.getMatches().size() == 0);
}

void testService() {
    Repo repo(3);
    Service service(repo);
    set<string> teams = {"t1", "t2", "t3"};
    service.addTeams(teams);

    Match m1("t1", 1, "t2", 0);
    Match m2("t1", 3, "t3", 1);
    Match m3("t3", 1, "t2", 2);

    service.addMatch(m1);
    service.addMatch(m2);
    service.addMatch(m3);

    assert (service.returnSortedTable().size() == 3);

    assert (service.findWinners()[0].first == "t1");
    assert (service.findWinners()[0].second == 6);
}

void testAll() {
    testEntity();
    testRepo();
    testService();
    cout << "All tests ran successfully! \n";
}

#endif //SUBIECT_EXAMEN_2_TESTS_H
