//
// Created by Feza Emir Çelik 22101910 (Section 2) on 7/5/2022.
//
#ifndef HW1_LEAGUEMANAGEMENTSYSTEM_H
#define HW1_LEAGUEMANAGEMENTSYSTEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;
#include <iostream>
#include "Team.h"
#include <array>




class LeagueManagementSystem {

private:
    int teamCount ;
    Team* teams;
public:
    LeagueManagementSystem();
    ~LeagueManagementSystem();
    void addTeam( const string name, const int year );
    void removeTeam( const string name );
    void addPlayer( const string teamName, const string playerName,
                    const int jersey, const int salary );
    void removePlayer( const string teamName, const string playerName );
    void transferPlayer( const string playerName,
                         const string departTeamName, const string arriveTeamName );
    void showAllTeams() const;
    void showTeam( const string name ) const;
    void showPlayer( const string name ) const;

    void expandArr(Team* teams, int newSize);
    int getIndexOfTeam(string teamName) const;
};


#endif //HW1_LEAGUEMANAGEMENTSYSTEM_H
