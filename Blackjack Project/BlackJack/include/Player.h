#ifndef PLAYER_H
#define PLAYER_H

#include "Human.h"
#include <string>

class Player: public Human{

private:
    string name;
    int cash, bet;           // Player's Cash, Player's Bet
    int wins, loses;         // Player's Stats (number of wins and loses)

public:
    Player();

    int getBet();
    int getCash();
    int getWins();
    int getLoses();
    string getName();

    void setName(string Name);
    void setBet(int b);
    void addCash(int c);
    void incrementWins();
    void incrementLoses();
    void clearCards();
};

#endif