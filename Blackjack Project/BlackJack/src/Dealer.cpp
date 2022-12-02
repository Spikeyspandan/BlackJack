#include "Dealer.h"
#include <iostream>

// Prints first card revealed and second card hidden
std::vector<char> Dealer::printFirstCard(){
    vector <char> dealer_card;
    
    dealer_card.push_back(hand[0].getNumber());

    return dealer_card;
}