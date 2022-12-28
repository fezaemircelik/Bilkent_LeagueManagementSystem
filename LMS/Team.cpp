//
// Created by Feza Emir Çelik 22101910 (Section 2) on 7/5/2022.
//

#include "Team.h"

Team::Team() {}
Team::Team(string teamName, int year) {
    this->teamName = teamName;
    this->year = year;
    this->playerCount = 0;
    this->players = nullptr;
    this->totalSalary = 0;
}

Team::~Team() {
    if(this->playerCount == 0){
        this->players == nullptr;
        return;
    }
    else{
        delete[] this->players;
        players = nullptr;
    }
}


string Team::getName() {
    return this->teamName;
}

void Team::setName(string teamName) {
    this->teamName = teamName;
}

int Team::getYear() {
    return this->year;
}

void Team::setYear(int year) {
    this->year = year;
}

Player* Team::getPlayers() {
    return this->players;
}

void Team::setPlayers(Player* players) {
    this->players = players;
}

void Team::addPlayer(Player newPlayer){
    bool checker = true;
    for (int i = 0; i < playerCount; i++){//this will check whether the player is in the team or not
        if (newPlayer.getPlayerName() == players[i].getPlayerName()){
            checker = false;
            cout << "This player alredy exists in " << this->getName() << "." << endl;
        }
    }
    for (int i = 0; i < playerCount; i++){//this will check whether the jersey number is used or not
        if (newPlayer.getjerseyNo() == players[i].getjerseyNo()){
            checker = false;
            cout << "Cannot add player. Jersey number " << newPlayer.getjerseyNo() << " already exists in team " << this->getName() << "." << endl;
        }
    }
    if (checker){
        if(this->playerCount == 0){
           newPlayer.setTeamName(this->getName());
           players = nullptr;
           playerCount += 1;
           players = new Player[playerCount];
           players[playerCount - 1] = newPlayer;
           increaseSalary(newPlayer.getSalary());
        }
        else{
            newPlayer.setTeamName(this->getName());
            Player* tmp = new Player[playerCount];
            for (int i = 0; i < playerCount; i++){
                tmp[i] = Player(players[i].getPlayerName(), players[i].getTeamName(), players[i].getjerseyNo(), players[i].getSalary());
            }
            playerCount += 1;
            delete[] players;   players = nullptr;
            players = new Player[playerCount];
            for (int i = 0; i < playerCount - 1; i++){
                players[i] = Player(tmp[i].getPlayerName(), tmp[i].getTeamName(), tmp[i].getjerseyNo(), tmp[i].getSalary());
            }
            delete[] tmp;  tmp = nullptr;
            players[playerCount - 1] = newPlayer;
            increaseSalary(newPlayer.getSalary());
        }
    }
    //if (checker){
    //    this->expandArr(this->players, playerCount+1);
    //    playerCount++;
    //    players[playerCount-1] = newPlayer;
    //    this->increaseSalary(newPlayer.getSalary());
    //}
}

void Team::expandArr(Player *players, int newSize) {
    int oldSize = this->playerCount;
    Player * tempArr = new Player[newSize];
    if(oldSize == 0){
        players = new Player[1];
    }
    else {
        for(int i = 0; i < oldSize; i++){//this loop will put the players from ex array to the new one
            tempArr[i] = Player(players[i].getPlayerName(),players[i].getTeamName(),players[i].getjerseyNo(),players[i].getSalary());
        }
        delete[] players;players = nullptr;

        players = new Player[newSize];
        for(int i = 0; i < oldSize; i++){//this loop equals 'players' array to the temporary one
            this->players[i] = Player(tempArr[i].getPlayerName(),tempArr[i].getTeamName(),tempArr[i].getjerseyNo(),tempArr[i].getSalary());
        }
        delete[] tempArr;tempArr = nullptr;
    }
}

void Team::increaseSalary(int salary) {
    this->totalSalary += salary;
}

void Team::removePlayer(string playerName) {
    bool checker = false;
    int indexOfPlayer;
    for (int i = 0; i < playerCount; i++){
        if (playerName == players[i].getPlayerName()){
            checker = true;
            indexOfPlayer = i;
            i = playerCount;
        }
    }
    if (checker){
        this->totalSalary = totalSalary - players[indexOfPlayer].getSalary();
        int oldPlayerCount = playerCount;
        int newPlayerCount = playerCount - 1;
        Player * tempArr = new Player[newPlayerCount];
        for (int i = 0; i < indexOfPlayer; i++){
            tempArr[i] = Player(players[i].getPlayerName(),players[i].getTeamName(),players[i].getjerseyNo(),players[i].getSalary());
        }
        for (int i = indexOfPlayer; i < newPlayerCount; i++){
            tempArr[i] = Player(players[i+1].getPlayerName(),players[i+1].getTeamName(),players[i+1].getjerseyNo(),players[i+1].getSalary());
        }
        delete[] players;players = nullptr;
        players = new Player[newPlayerCount];
        for (int i = 0; i < newPlayerCount; i++){
            players[i] = Player(tempArr[i].getPlayerName(),tempArr[i].getTeamName(),tempArr[i].getjerseyNo(),tempArr[i].getSalary());
        }
        delete[] tempArr;tempArr = nullptr;
        this->playerCount--;
        cout << "Removed player " << playerName << " from team " << this->getName() << "." << endl;
    }
    else{
        cout<< "Cannot remove player. Player " << playerName << " does not exist." << endl;
    }
}

int Team::getJerseyNumber(string name) {
    int playerIndex = 0;
    for(int i = 0; i < playerCount; i++){
        if (name == players[i].getPlayerName()){
            playerIndex = i;
            i = playerCount;
        }
    }
    int jerseyNo = players[playerIndex].getjerseyNo();
    return jerseyNo;
}

int Team::getSalary(string name) {
    int playerIndex = 0;
    for(int i = 0; i < playerCount; i++){
        if (name == players[i].getPlayerName()){
            playerIndex = i;
            i = playerCount;
        }
    }
    int salary = players[playerIndex].getSalary();
    return salary;
}

int Team::getPlayerCount() {
    return playerCount;
}

int Team::getTotalSalary() {
    return totalSalary;
}




