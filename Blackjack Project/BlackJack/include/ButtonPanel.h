#ifndef BUTTONPANEL_H_
#define BUTTONPANEL_H_

#include "ButtonDemo.h"
#include "Choice.h"
#include "Start.h"
#include "Game.h"
#include "Player.h"
#include "Dealer.h"
#include "Deck.h"

/**
 * The button panel of the application frame.
 */
class ButtonPanel : public wxPanel
{
public:
    volatile int hit_case ;

    ButtonPanel(wxFrame *parent) : wxPanel(parent, wxID_ANY)
    {
        init();
    }

    void on_continue_playing(wxCommandEvent& event);
    void on_increase_bet(wxCommandEvent& event);
    void on_decrease_button(wxCommandEvent& event);

    void on_new_Game(wxCommandEvent& event);
    void on_exit(wxCommandEvent& event);
    void on_hit(wxCommandEvent& event);
    void on_done(wxCommandEvent& event);

    void on_stand(wxCommandEvent& event);
    void on_deal_card(wxCommandEvent& event);
    void on_show_card(wxCommandEvent& event);
    void on_play_game(wxCommandEvent& event);
    void get_card();
    void on_increase(wxCommandEvent& event);

    void on_decrease(wxCommandEvent& event);
    void EnterName(wxCommandEvent& event);
    string Message;

private:

  bool flag;
  wxPanel* m_imagePanel;
  wxImage m_image;
  wxBitmap m_scaledBg;
  Player player;   // Player in the game (user)
  Dealer dealer;   // Dealer in the game
  Deck deck; 
  Game game;
  Card card;
  wxStaticText *chosen_button_name;
  wxPanel *Dealer_player_panel;
  wxPanel *Starter_panel;
  wxPanel *moves_panel;
  wxPanel *player_sum_panel;
  wxPanel *betting_panel;
  wxPanel *game_info_panel;
  wxStaticText *wins_counter;
  wxStaticText *loss_counter;
  wxStaticText *cash_counter;
  wxStaticText *bet_counter;
  wxStaticText *sum_counter;
  wxStaticText *dealer_sum;
  wxStaticText *game_type;
  wxStaticText *winner_text;
  wxStaticText *player_text;

    void init();
    ButtonPanel();
    void OnImagePanelPaint(wxPaintEvent&); 
    void CreateScaledBg();
    void update_button_choice_text(const Choice choice);
    void new_game_button();
    void dealer_player();
    void play_game_button();
    void moves_buttons();
    void betting_buttons();
    void display_player_sum();
    
    void get_info( bool flag);
    void GameInfoPanel();
    void dealer_game();
    void Dealer_panel(vector<wxPanel *> panels, wxSizer* sizer);
    void SetStartMenuVisibility(bool is_shown);
    void SetOptionsVisibility(bool is_shown);
    void SetGameVisibility(bool is_shown);
    void SetGameInfoVisibility(bool is_shown);
    void AddSubPanelsToMainPanel(vector<wxPanel *> panels, wxSizer* sizer);
};

#endif /* BUTTONPANEL_H_ */
