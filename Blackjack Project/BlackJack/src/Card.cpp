#include "Card.h"
#include <iostream>

Card::Card(){
    card_number = 0;
    suit = '\0';
    block = false;
}

Card::Card(int no, char s){
    card_number = no;
    suit = s;
    block = false;
}

int Card::getNumber(){
    return card_number;
}

char Card::getSuit(){
    return suit;
}  
bool Card::getBlock(){
    return block;
}

void Card::setNumber(int num){
    card_number = num;
}
void Card::setSuit(char c){
    suit = c;
}
void Card::setBlock(bool b){
    block = b;
}

char Card::getPrintNumber(){

    return card_number;
}

string Card::card_info(char suit,int num){
    card['B'][0]    = "Cards/back_of_card.png";

    card['C'][1]    = "Cards/Clubs/ace_of_clubs.png";
    card['C'][2]    = "Cards/Clubs/2_of_clubs.png";
    card['C'][3]    = "Cards/Clubs/3_of_clubs.png";
    card['C'][4]    = "Cards/Clubs/4_of_clubs.png";
    card['C'][5]    = "Cards/Clubs/5_of_clubs.png";
    card['C'][6]    = "Cards/Clubs/6_of_clubs.png";
    card['C'][7]    = "Cards/Clubs/7_of_clubs.png";
    card['C'][8]    = "Cards/Clubs/8_of_clubs.png";
    card['C'][9]    = "Cards/Clubs/9_of_clubs.png";
    card['C'][10]   =  "Cards/Clubs/10_of_clubs.png";
    card['C'][11]   = "Cards/Clubs/jack_of_clubs.png";
    card['C'][12]   = "Cards/Clubs/queen_of_clubs.png";
    card['C'][13]   = "Cards/Clubs/king_of_clubs.png";

    card['S'][1]    = "Cards/Spades/ace_of_spades.png";
    card['S'][2]    = "Cards/Spades/2_of_spades.png";
    card['S'][3]    = "Cards/Spades/3_of_spades.png";
    card['S'][4]    = "Cards/Spades/4_of_spades.png";
    card['S'][5]    = "Cards/Spades/5_of_spades.png";
    card['S'][6]    = "Cards/Spades/6_of_spades.png";
    card['S'][7]    = "Cards/Spades/7_of_spades.png";
    card['S'][8]    = "Cards/Spades/8_of_spades.png";
    card['S'][9]    = "Cards/Spades/9_of_spades.png";
    card['S'][10]   = "Cards/Spades/10_of_spades.png";
    card['S'][11]   = "Cards/Spades/jack_of_spades.png";
    card['S'][12]   = "Cards/Spades/queen_of_spades.png";
    card['S'][13]   = "Cards/Spades/king_of_spades.png";

    card['D'][1]    = "Cards/Diamonds/ace_of_diamonds.png";
    card['D'][2]    = "Cards/Diamonds/2_of_diamonds.png";
    card['D'][3]    = "Cards/Diamonds/3_of_diamonds.png";
    card['D'][4]    = "Cards/Diamonds/4_of_diamonds.png";
    card['D'][5]    = "Cards/Diamonds/5_of_diamonds.png";
    card['D'][6]    = "Cards/Diamonds/6_of_diamonds.png";
    card['D'][7]    = "Cards/Diamonds/7_of_diamonds.png";
    card['D'][8]    = "Cards/Diamonds/8_of_diamonds.png";
    card['D'][9]    = "Cards/Diamonds/9_of_diamonds.png";
    card['D'][10]   = "Cards/Diamonds/10_of_diamonds.png";
    card['D'][11]   = "Cards/Diamonds/jack_of_diamonds.png";
    card['D'][12]   = "Cards/Diamonds/queen_of_diamonds.png";
    card['D'][13]   = "Cards/Diamonds/king_of_diamonds.png";

    card['H'][1]    = "Cards/Hearts/ace_of_hearts.png";
    card['H'][2]    = "Cards/Hearts/2_of_hearts.png";
    card['H'][3]    = "Cards/Hearts/3_of_hearts.png";
    card['H'][4]    = "Cards/Hearts/4_of_hearts.png";
    card['H'][5]    = "Cards/Hearts/5_of_hearts.png";
    card['H'][6]    = "Cards/Hearts/6_of_hearts.png";
    card['H'][7]    = "Cards/Hearts/7_of_hearts.png";
    card['H'][8]    = "Cards/Hearts/8_of_hearts.png";
    card['H'][9]    = "Cards/Hearts/9_of_hearts.png";
    card['H'][10]   = "Cards/Hearts/10_of_hearts.png";
    card['H'][11]   = "Cards/Hearts/jack_of_hearts.png";
    card['H'][12]   = "Cards/Hearts/queen_of_hearts.png";
    card['H'][13]   = "Cards/Hearts/king_of_hearts.png";

    return card[suit][num];
}

void Card::mapping_cards(){

}