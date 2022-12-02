#include "Deck.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
void Deck::initializeDeck(){
    deck.clear();
    char suits[4] = {'S','H','D','C'};
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            Card c(j+1,suits[i]);
            deck.push_back(c);
        }
    }
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(deck.begin(), deck.end(),std::default_random_engine(seed));
}

int Deck::getSize(){
    return deck.size();
}

Card Deck::deal(){
    int val = (rand()%(deck.size()));
    Card t = deck[val];
    deck.erase(deck.begin()+val);
    return t;
}