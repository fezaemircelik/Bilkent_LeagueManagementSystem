//
// Created by Feza Emir Çelik 22101910 (Section 2) on 7/5/2022.
//

#ifndef HW1_TEAM_H
#define HW1_TEAM_H
#include <iostream>
using namespace std;
#include "Player.h"


class Team {
public:
    Team();

    ~Team();
    Team(string teamName, int year);
    string getName();
    void setName(string teamName);
    int getYear();
    void setYear(int year);
    Player* getPlayers();
    void setPlayers(Player* players);
    void addPlayer(Player newPlayer);
    void removePlayer(string playerName);

    void expandArr(Player * players, int newSize);

    void increaseSalary(int salary);

    int getJerseyNumber(string name);
    int getSalary(string name);

    int getPlayerCount();
    int getTotalSalary();
private:
    string teamName;
    int year;
    int playerCount = 0;
    int totalSalary;
    Player* players;
};

#endif //HW1_TEAM_H
