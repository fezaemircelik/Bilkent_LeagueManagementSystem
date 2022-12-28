#include <iostream>
using namespace std;
#include "LeagueManagementSystem.h"
int main() {
    LeagueManagementSystem LMS;


    //Simple Transfer Check
    LMS.addTeam("t1", 11);
    LMS.addTeam("t2", 12);

    LMS.addPlayer("t1", "p1", 1, 1);
    LMS.transferPlayer("p1", "t1", "t2");
    LMS.showAllTeams();
    LMS.showPlayer("p1");
    LMS.showTeam("t2");

    LMS.removePlayer("t1", "p1");
    LMS.addPlayer("t2", "p3", 1,1);

    LMS.removeTeam("t1");
    LMS.removeTeam("t2");
    cout<<endl;

    //Multiple Transfers

    LMS.addTeam("t1", 11);
    LMS.addTeam("t2", 12);

    LMS.addPlayer("t1", "p1", 1, 1);
    LMS.addPlayer("t1", "p2", 2, 2);
    LMS.addPlayer("t1", "p3", 3, 3);

    LMS.transferPlayer("p1", "t1", "t2");
    LMS.transferPlayer("p2", "t1", "t2");
    LMS.transferPlayer("p3", "t1", "t2");

    LMS.removePlayer("t1", "p1");
    LMS.removePlayer("t1", "p2");
    LMS.removePlayer("t1", "p3");

    LMS.addPlayer("t1", "p11", 1, 1);
    LMS.addPlayer("t1", "p12", 2, 2);
    LMS.addPlayer("t1", "p13", 3, 3);

    LMS.addPlayer("t2", "p21", 1, 1);
    LMS.addPlayer("t2", "p22", 2, 2);
    LMS.addPlayer("t2", "p23", 3, 3);

    LMS.showAllTeams();
    LMS.showPlayer("p1");
    LMS.showPlayer("p2");
    LMS.showPlayer("p3");
    LMS.showTeam("t1");
    LMS.showTeam("t2");
    LMS.removeTeam("t1");
    LMS.removeTeam("t2");
    cout<<endl;

    //Transfer Cycle

    LMS.addTeam("t1", 11);
    LMS.addTeam("t2", 12);
    LMS.addTeam("t3", 13);
    LMS.addPlayer("t1", "p1", 1, 1);
    LMS.addPlayer("t1", "p2", 2, 1);
    LMS.addPlayer("t2", "p3", 2, 1);
    LMS.addPlayer("t3", "p4", 2, 1);

    LMS.transferPlayer("p1", "t1", "t2");
    LMS.showPlayer("p1");
    LMS.transferPlayer("p1", "t2", "t3");
    LMS.showPlayer("p1");
    LMS.transferPlayer("p1", "t3", "t1");
    LMS.showPlayer("p1");
    LMS.showAllTeams();

    LMS.removeTeam("t1");
    LMS.removeTeam("t2");
    LMS.removeTeam("t3");
    cout<<endl;

    // Jersey
    LMS.addTeam("t1", 11);
    LMS.addTeam("t2", 12);
    LMS.addPlayer("t1", "p1", 1, 1);
    LMS.addPlayer("t2", "p2", 1, 1);
    LMS.transferPlayer("p1", "t1", "t2");

    LMS.showPlayer("p1");

    LMS.removePlayer("t2", "p2");
    LMS.transferPlayer("p1", "t1", "t2");
    LMS.showPlayer("p1");
    LMS.addPlayer("t2", "p3", 1,1);
    LMS.removePlayer("t2", "p1");
    LMS.addPlayer("t2", "p3", 1,1);
    LMS.showPlayer("p1");
    LMS.showPlayer("p2");
    LMS.showPlayer("p3");
    LMS.removeTeam("t1");
    LMS.removeTeam("t2");
    LMS.removeTeam("t3");
    cout<<endl;

    // Depart team

    LMS.addTeam("t1", 11);
    LMS.addTeam("t2", 12);
    LMS.addPlayer("t1", "p1", 1, 1);
    LMS.removeTeam("t1");
    LMS.transferPlayer("p1", "t1", "t2");
    LMS.addTeam("t1", 11);
    LMS.addPlayer("t1", "p1", 1, 1);
    LMS.transferPlayer("p1", "t1", "t2");
    cout<<endl;

    // Arrive team

    LMS.addTeam("t1", 11);
    LMS.addTeam("t2", 12);
    LMS.addPlayer("t1", "p1", 1, 1);
    LMS.removeTeam("t2");
    LMS.transferPlayer("p1", "t1", "t2");
    LMS.addTeam("t2", 12);
    LMS.transferPlayer("p1", "t1", "t2");

    return 0;
}
