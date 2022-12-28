//
// Created by Feza Emir Çelik 22101910 (Section 2) on 7/5/2022.
//

#include "Player.h"

Player::Player() {
    this->playerName = "Unknown Player Name";
    this->teamName = "Unknown Team Name";
    this->jerseyNo = 0; //this is actually not true!!
    this->salary = 0; //this is actually not true!!
}

Player::Player(string playerName, string teamName, int jerseyNo, int salary) {
    this->playerName = playerName;
    this->teamName = teamName;
    this->jerseyNo = jerseyNo;
    this->salary = salary;
}

string Player::getPlayerName() {
    return this->playerName;
}

void Player::setPlayerName(string playerName) {
    this->playerName = playerName;
}

string Player::getTeamName() {
    return this->teamName;
}

void Player::setTeamName(string teamName) {
    this->teamName = teamName;
}

int Player::getjerseyNo() {
    return this->jerseyNo;
}

void Player::setJerseyNo(int jerseyNo) {
    this->jerseyNo = jerseyNo;
}

int Player::getSalary() {
    return salary;
}

void Player::setSalary(int salary){
    this->salary = salary;
}