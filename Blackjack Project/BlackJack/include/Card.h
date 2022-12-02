#ifndef CARD_H
#define CARD_H
#include <map>
#include <string>
#include <iostream>
using namespace std;

class Card{
    
    private:
        map<int, map<char, string>> card;
        int card_number; 
        char suit;
        bool block;

    public:
        Card();
        Card(int no, char s);

        void mapping_cards();
        void setNumber(int num);
        void setSuit(char c);
        void setBlock(bool b);
        char getPrintNumber();
        int getNumber();
        char getSuit();
        bool getBlock();
        string card_info(char suit, int num); //Returns path of card image to display when needed
};

#endif