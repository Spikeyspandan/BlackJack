#include "Human.h"
#include <iostream>

// Default Constructor
Human::Human(){
    sum = 0;
}

// Getter Function for sum to check end of game
int Human::getSum(){
    switchAce();
    return sum;
}

// Switches Ace between 1 and 11
void Human::switchAce(){
    if(sum>21){
        for(int i=0;i<hand.size();i++){
                if(hand[i].getNumber()==1 && !(hand[i].getBlock())){
                    hand[i].setBlock(true);
                    sum-=10;
                    return;
                }
        }
    }
}

// Adds card to Human's hand
void Human::addCard(Card c){
    hand.push_back(c);
    if(c.getNumber() > 10){
        c.setNumber(10);
    }
    else if (c.getNumber()==1){
        c.setNumber(11);
    }
    sum+= c.getNumber();
}

// Clears Human's hand
void Human::clearCards(){
    hand.clear();
    sum = 0;
}

// Prints Human's cards
std::vector<char> Human::displayCards(){
    std::vector <char> human_card;
        for(int j = 0; j < hand.size(); j++){
             human_card.push_back(hand[j].getPrintNumber());
        }
    return human_card;
}

std::vector<char> Human::suitCards(){
    std::vector <char> human_card;
        for(int j = 0; j < hand.size(); j++){
             human_card.push_back(hand[j].getSuit());
        }
    return human_card;
}