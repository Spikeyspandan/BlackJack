#ifndef GAME_HPP
#define GAME_HPP

#include "Deck.h"
#include "Dealer.h"
#include "Player.h"
#include "wx/wx.h"
#include <string>

class Game{

    private:
        Player player;   // Player in the game (user)
        Dealer dealer;   // Dealer in the game
        Deck deck;       // Deck of cards in the game
       

    public:
    
        int bet_value =0;

        Game();
        void dealDealer();
        char compareSum();
        bool checkWins();
        char checkEnd();
        void startBet(int c);
        
        void beginGame();
        void beginMenu(bool rep, std::string message);
        void sGame();
        void hit_case();
        void clear_cards();
        int get_bet();
        int get_sum();
        int get_dealer_sum();
        string displayWinner();
        string check_sum();
        std::vector <char> player_cards();
        std::vector <char> player_suits();
        std::vector <char> dealer_cards();
        std::vector <char> dealer_suits();

        int player_wins();
        int player_cash();
        int player_loses();
};

#endif