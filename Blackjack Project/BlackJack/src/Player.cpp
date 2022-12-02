#include "Player.h"
#include <iostream>


Player::Player(){
    name = "";
    bet = 0;
    cash = 1000;
    wins = 0;
    loses = 0;
}

int Player::getBet(){
    return bet;
}

int Player::getCash(){
    return cash;
}

int Player::getWins(){
    return wins;
}

int Player::getLoses(){
    return loses;
}

string Player::getName(){
    return name;
}

void Player::setName(string Name){
    name = Name;
}

void Player::setBet(int b){
    cash -= b;
    bet += b;
}

void Player::addCash(int c){
    cash += c;
}

void Player::incrementWins(){
    wins += 1;
}


void Player::incrementLoses(){
    loses += 1;
}

void Player::clearCards(){
    Human::clearCards();
    bet = 0;
}