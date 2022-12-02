#include "Game.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

Game::Game(){
    deck.initializeDeck();
}


void Game::dealDealer(){
    
    while (dealer.getSum() < 17){
        dealer.addCard(deck.deal());
            
    }
}

char Game::compareSum(){
    if(player.getSum()>dealer.getSum()){
        return 'p';
    }
    else if(dealer.getSum()>player.getSum()){

        return 'd';
    }
    else{

        return 'n';
    }
}

bool Game::checkWins(){
    switch(checkEnd()){
        case 'f': return false;
        case 'd': player.incrementLoses(); return true;
        case 'p': player.incrementWins();
                  player.addCash(bet_value*2);
                  return true;
    }
    return false;
}

char Game::checkEnd(){
    if(dealer.getSum()>21 || player.getSum()>21){
       
        if(dealer.getSum()>21){
            return 'p';
        }
        else if(player.getSum()>21){
            return 'd';
        }
    }
    else if(dealer.getSum()==21 || player.getSum()==21){
    
        if(dealer.getSum()==21){
            return 'd';
        }
        else if(player.getSum()==21){
            return 'p';
        }
    }
    return 'f';
}


string Game::check_sum()
{
    if(dealer.getSum()>21 || player.getSum()>21){
        
        if(dealer.getSum()>21){
            return "Dealer BUST";
        }
        else if(player.getSum()>21){
            return "Player BUST";
        }
    }
    else if(dealer.getSum()==21 || player.getSum()==21){
        
        if(dealer.getSum()==21){
            return "Dealer BLACKJACK";
        }
        else if(player.getSum()==21){
            return "Player BLACKJACK";
        }
    }
    return "";
}

void Game::startBet(int c){
    if(player.getCash()>0){
     
        switch(c){
            case 87: if(player.getCash() >= 5){
                            player.setBet(5);
                         }
                         break;
            case 83: if(player.getBet()>=5){
                            player.setBet(-5);
                         }
                         break;
            }
    }

}


int Game::get_bet()
{
    return player.getBet();
}

void Game::sGame()
{
    if(player.getBet()>0){
        bet_value = player.getBet();
        deck.initializeDeck();
        player.clearCards();
        dealer.clearCards();
        player.addCard(deck.deal());
        dealer.addCard(deck.deal());
        player.addCard(deck.deal());
        dealer.addCard(deck.deal());
    }
    
}

void Game::clear_cards()
{
    player.clearCards();
}
void Game:: hit_case()
{
    
    player.addCard(deck.deal());
    

}

std::vector <char> Game::player_cards()
{
   
vector <char> asd = player.displayCards();
return asd;
}

std::vector <char> Game::player_suits()
{
vector <char> asd = player.suitCards();
return asd;
}

std::vector <char> Game::dealer_cards()
{
   
vector <char> asd = dealer.displayCards();
return asd;
}

std::vector <char> Game::dealer_suits()
{
vector <char> asd = dealer.suitCards();
return asd;
}


int Game::get_sum()
{
    return player.getSum();
}

int Game::get_dealer_sum()
{
    return dealer.getSum();
}



void Game::beginGame(){
     if(dealer.getSum()<player.getSum() )
    {
        dealDealer();
    }
    if(!checkWins())
    {
        cout<<compareSum()<<endl;
        switch(compareSum()){

        case 'p':   player.incrementWins();
                    player.addCash(bet_value*2);break;                    
        case 'd':   player.incrementLoses(); break;
        case 'n':   player.addCash(bet_value); break;
        }
    }
    
}

string Game::displayWinner()
{   
    if(player.getSum()>21)
    {
        return "Dealer Wins";
    }
    else if (dealer.getSum()>21)
    {
        return "Player Wins";
    }
    if(player.getSum()>dealer.getSum()){
        return "Player Wins";
    }
    else if(dealer.getSum()>player.getSum()){

        return "Dealer Wins";
    }
    else{

        return "Draw";
    }
}


int Game::player_wins()
{
   return player.getWins();
}

int Game::player_cash()
{
    return player.getCash();
}

int Game:: player_loses()
{
    return player.getLoses();
}

