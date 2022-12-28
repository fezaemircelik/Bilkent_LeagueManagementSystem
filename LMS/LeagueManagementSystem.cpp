//
// Created by Feza Emir Çelik 22101910 (Section 2) on 7/5/2022.
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#include "LeagueManagementSystem.h"

void LeagueManagementSystem::addTeam(const string name, const int year) {
    bool checker = true;
    for (int i = 0; i < teamCount; i++){
        if (name == teams[i].getName()){
            checker = false;
            cout<< "Cannot add team. Team " << name << " already exists." << endl;
        }
    }
    if(checker){
        //if(teamCount == 0){
        //    this->teamCount += 1;
        //    teams = nullptr;
        //    teams = new Team[teamCount];
        //    teams[teamCount - 1] = Team(name, year);
        //}
        //else{
            Team* tmp = new Team[teamCount];
            for(int i = 0; i < teamCount; i++){
                tmp[i] = Team(teams[i].getName(),teams[i].getYear());
            }
            this->teamCount += 1;
            delete[] teams; teams = nullptr;
            teams = new Team[teamCount];
            for(int i = 0; i < teamCount; i++){
                if(i != teamCount - 1){
                    teams[i] = Team(tmp[i].getName(), tmp[i].getYear());
                }
                else{
                    teams[i] = Team(name,year);
                }
            }
        //}
        cout << "Added team " << name << "." << endl;
    }
    //if(checker){
    //    this->expandArr(this->teams,teamCount+1);
    //    teamCount++;
    //    teams[teamCount-1] = Team(name,year);
    //}
}

void LeagueManagementSystem::removeTeam(const string name) {
    bool checker = false;
    int indexOfTeam;
    for(int i = 0; i < teamCount; i++){
        if (name == teams[i].getName()){
            checker = true;
            indexOfTeam = i;
            i = teamCount;
        }
    }
    if (checker){
        int oldTeamCount = teamCount;
        int newTeamCount = teamCount - 1;
        Team * tempArr = new Team[newTeamCount];
        for (int i = 0; i < indexOfTeam; i ++){
            tempArr[i] = Team(teams[i].getName(), teams[i].getYear());
        }
        for (int i = indexOfTeam; i < newTeamCount; i++){
            tempArr[i] = Team(teams[i+1].getName(), teams[i+1].getYear());
        }
        delete[] teams;teams = nullptr;
        teams = new Team[newTeamCount];
        for (int i = 0; i < newTeamCount; i++){
            teams[i] = Team(tempArr[i].getName(),tempArr[i].getYear());
        }
        delete[] tempArr;tempArr = nullptr;
        this->teamCount--;
        cout << "Removed team " << name << "." << endl;
    }
    else{
        cout << "Cannot remove team. Team " << name << " does not exist." << endl;
    }
}

void LeagueManagementSystem::expandArr(Team *teams, int newSize) {
    int oldSize = this->teamCount;
    Team * tempArr = new Team[newSize];
    if(oldSize == 0){
        delete teams;teams = nullptr;

        teams = new Team[newSize];
    }
    else{
        for (int i = 0; i < oldSize; i++){//this loop will put the teams from ex array to the new one
            tempArr[i] = Team(teams[i].getName(),teams[i].getYear());
        }
        delete[] teams;teams = nullptr;

        teams = new Team[newSize];
        for (int i = 0; i < oldSize; i++){
            teams[i] = Team(tempArr[i].getName(), tempArr[i].getYear());
        }
        delete[] tempArr;tempArr = nullptr;
    }
}

int LeagueManagementSystem::getIndexOfTeam(string teamName) const {
    int index = 0;
    for (int i = 0; i < this->teamCount; i++){
        if (teamName == this->teams[i].getName()){
            index = i;
            i = teamCount+1;
        }
    }
    return index;
}

void
LeagueManagementSystem::addPlayer(const string teamName, const string playerName, const int jersey, const int salary) {
    bool checker = false;
    for (int i = 0; i < teamCount; i++){
        if (teamName == teams[i].getName()){
            checker = true;
        }
    }
    if (checker){
        int futurePlayerCount = teams[this->getIndexOfTeam(teamName)].getPlayerCount() + 1;
        teams[this->getIndexOfTeam(teamName)].addPlayer(Player(playerName,teamName,jersey,salary));
        if(futurePlayerCount == teams[this->getIndexOfTeam(teamName)].getPlayerCount()){
            cout << "Added player " << playerName << " to team " << teamName << "." << endl;
        }
    }
    else{
        cout << "Cannot add player. Team " << teamName << " does not exist." << endl;
    }
}

void LeagueManagementSystem::removePlayer(const string teamName, const string playerName) {
    bool checker = false;
    for (int i = 0; i < teamCount; i++){
        if (teamName == teams[i].getName()){
            checker = true;
        }
    }
    if(checker){
        teams[this->getIndexOfTeam(teamName)].removePlayer(playerName);
        //cout << "Removed player " << playerName << " from team " << teamName << "." << endl;
    }
    else{
        cout << "Cannot remove player. Team " << teamName << " does not exist." << endl;
    }
}

void LeagueManagementSystem::transferPlayer(const string playerName, const string departTeamName, const string arriveTeamName) {
    bool checker = false;
    bool problemDepart = true;
    bool problemArrive = true;
    bool problemPlayer = true;
    for (int i = 0; i < teamCount; i++){
        if (departTeamName == teams[i].getName()){
            problemDepart = false;
        }
        if(arriveTeamName == teams[i].getName()){
            problemArrive = false;
        }
    }
    for(int i = 0; i < teams[this->getIndexOfTeam(departTeamName)].getPlayerCount(); i++){
        if(playerName == teams[this->getIndexOfTeam(departTeamName)].getPlayers()[i].getPlayerName()){
            problemPlayer = false;
        }
    }
    if(!problemArrive && !problemDepart && !problemPlayer){
        checker = true;
    }
    if (checker){
        //informations about the player
        int departTeamIndex = this->getIndexOfTeam(departTeamName);
        int arriveTeamIndex = this->getIndexOfTeam(arriveTeamName);
        int playerJersey = teams[departTeamIndex].getJerseyNumber(playerName);
        int playerSalary = teams[departTeamIndex].getSalary(playerName);

        //departure of the player
        teams[departTeamIndex].removePlayer(playerName);

        //arrival of the player
        teams[arriveTeamIndex].addPlayer(Player(playerName,arriveTeamName,playerJersey,playerSalary));
    }
    else{
        if(problemDepart){
            cout << "Cannot transfer player. Team " << departTeamName << " does not exist." << endl;
        }
        else if(problemArrive){
            cout << "Cannot transfer player. Team " << arriveTeamName << " does not exist." << endl;
        }
        else{
            cout << "Cannot transfer player. Player " << playerName << " does not exist." << endl;
        }
    }
}

void LeagueManagementSystem::showAllTeams() const {
    cout << "Teams in the league management system: " << endl;
    for (int i = 0; i < teamCount; i++){
        cout << teams[i].getName() << ", " << teams[i].getYear() << ", " << teams[i].getPlayerCount() << " players, " << teams[i].getTotalSalary() << " TL total salary" << endl;
    }
}

void LeagueManagementSystem::showTeam(const string name) const {
    bool checker = false;
    for(int i = 0; i < teamCount; i++){
        if(name == teams[i].getName()){
            checker = true;
        }
    }
    if(checker){
        int index = this->getIndexOfTeam(name);
        cout << "Team: " << endl;
        cout << teams[index].getName() << ", " << teams[index].getYear() << ", " << teams[index].getPlayerCount() << " players, " << teams[index].getTotalSalary() << " TL total salary" << endl;
        cout << "Player: " << endl;
        for (int i = 0; i < teams[index].getPlayerCount(); i++){
            cout << teams[index].getPlayers()[i].getPlayerName() << ", jersey " << teams[index].getPlayers()[i].getjerseyNo() << ", " << teams[index].getPlayers()[i].getSalary() << " TL total salary" << endl;
        }
    }
    else{
        cout << "Team " << name << " does not exist." << endl;
    }
}

void LeagueManagementSystem::showPlayer(const string name) const {
    string playerName = "";
    string teamName = "";
    int playerJersey = -1;
    int playerSalary = -1;
    for (int i = 0; i < teamCount; i++){
        for (int j = 0; j < teams[i].getPlayerCount(); j++){
            if (name == teams[i].getPlayers()[j].getPlayerName()){
                playerName = teams[i].getPlayers()[j].getPlayerName();
                teamName = teams[i].getPlayers()[j].getTeamName();
                playerJersey = teams[i].getPlayers()[j].getjerseyNo();
                playerSalary = teams[i].getPlayers()[j].getSalary();
            }
        }
    }

    cout << "Player: " << endl;
    cout <<playerName << ", jersey " << playerJersey << ", " << playerSalary << " TL salary" << endl;
    cout << "Plays in " << teamName << "." << endl;
}

LeagueManagementSystem::LeagueManagementSystem() {
    this->teamCount = 0;
    this->teams = new Team[teamCount];
}

LeagueManagementSystem::~LeagueManagementSystem() {

}







