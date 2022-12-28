//
// Created by Feza Emir Çelik 22101910 (Section 2) on 7/5/2022.
//

#ifndef HW1_PLAYER_H
#define HW1_PLAYER_H
#include <iostream>
using namespace std;


class Player {
private:
    string playerName;
    string teamName;
    int jerseyNo;
    int salary;
public:
    Player();
    Player(string playerName, string teamName, int jerseyNo, int salary);
    string getPlayerName();
    void setPlayerName(string playerName);
    string getTeamName();
    void setTeamName(string teamName);
    int getjerseyNo();
    void setJerseyNo(int jerseyNo);
    int getSalary();
    void setSalary(int salary);
};


#endif //HW1_PLAYER_H
