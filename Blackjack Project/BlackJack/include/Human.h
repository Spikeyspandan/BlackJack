#ifndef HUMAN_H
#define HUMAN_H

#include "Card.h"
#include <vector>

class Human{

    protected:
        std::vector<Card> hand;
        int sum;

    public:
        Human();
        int getSum();
        void switchAce();
        void addCard(Card c);
        void clearCards();
        std::vector<char> displayCards();
        std::vector<char> suitCards();
};

#endif