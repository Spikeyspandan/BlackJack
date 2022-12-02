#include "ButtonPanel.h"


void ButtonPanel::init()
{
    wxSizer *main_panel_sizer = new wxBoxSizer(wxVERTICAL);
    
    Dealer_player_panel = new wxPanel(this, wxID_ANY);
    dealer_player(); 

    Starter_panel = new wxPanel(this, wxID_ANY);
    new_game_button();

    player_sum_panel = new wxPanel(this, wxID_ANY);
    play_game_button();
    
    moves_panel = new wxPanel(this, wxID_ANY);
    moves_buttons();

    betting_panel = new wxPanel(this, wxID_ANY);
    betting_buttons();

    game_info_panel = new wxPanel(this, wxID_ANY);
    GameInfoPanel();

    vector<wxPanel *> panels;
    vector<wxPanel *> panels1;
    panels1.push_back(Dealer_player_panel);
    panels.push_back(Starter_panel);
    panels.push_back(player_sum_panel);
    panels.push_back(moves_panel);
    panels.push_back(betting_panel);
    panels.push_back(game_info_panel);
    Dealer_panel(panels1,main_panel_sizer);
    main_panel_sizer->AddSpacer(200);
    AddSubPanelsToMainPanel(panels, main_panel_sizer);
    SetGameInfoVisibility(true);
    SetStartMenuVisibility(false);
    SetGameVisibility(false);
    SetOptionsVisibility(false);
    

 
    SetSizer(main_panel_sizer);
    hit_case = 0;
    
}


void ButtonPanel::SetStartMenuVisibility(bool is_shown)
{

  is_shown ? player_sum_panel->Enable() : player_sum_panel->Disable();
  player_sum_panel->Layout();
}

void ButtonPanel::SetOptionsVisibility(bool is_shown)
{
  is_shown ? betting_panel->Enable() : betting_panel->Disable();
  betting_panel->Layout();
}

void ButtonPanel::SetGameVisibility(bool is_shown)
{

  is_shown ? moves_panel->Enable() : moves_panel->Disable();
  moves_panel->Layout();
  
  
  moves_panel->Layout();
  
}
void ButtonPanel::SetGameInfoVisibility(bool is_shown)
{

  is_shown ? game_info_panel->Enable() : game_info_panel->Disable();
  game_info_panel->Layout();
  
  
  game_info_panel->Layout();
  
}



void ButtonPanel::dealer_player()
{
    
    wxSizer *dealer_sizer = new wxBoxSizer(wxVERTICAL);
   
    player_text = new wxStaticText(Dealer_player_panel, wxID_ANY,"PLAYER");
    wxStaticText *dealer_text = new wxStaticText(Dealer_player_panel, wxID_ANY,"DEALER");
    wxFont t_Font = dealer_text->GetFont();
    t_Font.SetPointSize( 20 );
    player_text->SetFont(t_Font);
    
  
    dealer_text->SetFont(t_Font);
  
  dealer_sizer->Add(player_text, 0, 0, 0);
  dealer_sizer->AddSpacer(180);
  dealer_sizer->Add(dealer_text, 0, 0, 0);
  Dealer_player_panel->SetForegroundColour(wxColor(255,255,255));
   Dealer_player_panel->SetSizer(dealer_sizer);
 

}
void ButtonPanel::play_game_button(){    
    wxSizer *play_button_sizer = new wxBoxSizer(wxHORIZONTAL);

    wxButton *start_game_button      = new wxButton(player_sum_panel, wxID_ANY, move_to_wxString(Start::PLAY_GAME));

    start_game_button->Bind    (wxEVT_BUTTON, &ButtonPanel::on_play_game, this); 
   

    play_button_sizer->Add(start_game_button, 0, 0, 0);
    play_button_sizer->AddSpacer(5);

    player_sum_panel->SetSizer(play_button_sizer);
}


void ButtonPanel::new_game_button(){  

    wxSizer *Starter_button_sizer = new wxBoxSizer(wxHORIZONTAL);

    wxButton *new_game_button      = new wxButton(Starter_panel, wxID_ANY, move_to_wxString(Start::NEW_GAME));
    wxButton *name_button      = new wxButton(Starter_panel, wxID_ANY, "Enter Name");
    wxButton *exit_game     = new wxButton(Starter_panel, wxID_ANY, move_to_wxString(Start::EXIT));

    new_game_button->Bind    (wxEVT_BUTTON, &ButtonPanel::on_new_Game, this); 
    exit_game->Bind    (wxEVT_BUTTON, &ButtonPanel::on_exit, this); 
    name_button->Bind    (wxEVT_BUTTON, &ButtonPanel::EnterName, this); 

    Starter_button_sizer->Add(new_game_button, 0, 0, 0);
    Starter_button_sizer->AddSpacer(5);
    Starter_button_sizer->Add(name_button, 0, 0, 0);
    Starter_button_sizer->AddSpacer(5);
    Starter_button_sizer->Add(exit_game, 0, 0, 0);
    Starter_button_sizer->AddSpacer(5);
    Starter_panel->SetSizer(Starter_button_sizer);
}

void ButtonPanel::moves_buttons(){
    wxSizer *button_sizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText *choose_text = new wxStaticText(moves_panel, wxID_ANY, wxT("Choose:"));
    wxButton *hit_button     = new wxButton(moves_panel, wxID_ANY, choice_to_wxString(HIT));
    wxButton *stand_button    = new wxButton(moves_panel, wxID_ANY, choice_to_wxString(STAND));

    
    hit_button->Bind    (wxEVT_BUTTON, &ButtonPanel::on_hit, this);
    stand_button->Bind   (wxEVT_BUTTON, &ButtonPanel::on_stand, this);
    

    button_sizer->Add(hit_button, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(stand_button, 0, 0, 0);
    button_sizer->AddSpacer(5);
    moves_panel->SetSizer(button_sizer);

}


void ButtonPanel::betting_buttons(){
    wxSizer *betting_button_sizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText *choose_text = new wxStaticText(betting_panel, wxID_ANY, wxT("Bet:"));
    wxButton *increase_button     = new wxButton(betting_panel, wxID_ANY, choice_to_wxString(INC));
    wxButton *decrease_button    = new wxButton(betting_panel, wxID_ANY, choice_to_wxString(DEC));
    wxButton *done_button    = new wxButton(betting_panel, wxID_ANY, choice_to_wxString(DONE));
    
    increase_button->Bind    (wxEVT_BUTTON, &ButtonPanel::on_increase, this);
    decrease_button->Bind   (wxEVT_BUTTON, &ButtonPanel::on_decrease, this);
    done_button->Bind   (wxEVT_BUTTON, &ButtonPanel::on_done, this);
    

    betting_button_sizer->Add(increase_button, 0, 0, 0);
    betting_button_sizer->AddSpacer(5);
    betting_button_sizer->Add(decrease_button, 0, 0, 0);
    betting_button_sizer->AddSpacer(5);
    betting_button_sizer->Add(done_button, 0, 0, 0);
    betting_button_sizer->AddSpacer(5);
    betting_panel->SetSizer(betting_button_sizer);
}


void ButtonPanel::GameInfoPanel()
{
  wxSizer *game_info_sizer = new wxGridSizer(3, 1, 4);
  wxStaticText *wins_text = new wxStaticText(game_info_panel, wxID_ANY,"Wins:");
  wins_counter = new wxStaticText(game_info_panel, wxID_ANY, "");
 
  wxStaticText *loss_text = new wxStaticText(game_info_panel, wxID_ANY,
                                               "Loss:");

  loss_counter = new wxStaticText(game_info_panel, wxID_ANY, "");

  wxStaticText *cash_text = new wxStaticText(game_info_panel, wxID_ANY,
                                               "Cash:");

  cash_counter = new wxStaticText(game_info_panel, wxID_ANY, ""); 
  
  wxStaticText *bet_text = new wxStaticText(game_info_panel, wxID_ANY,
                                               "Bet:");

  bet_counter = new wxStaticText(game_info_panel, wxID_ANY, ""); 

   wxStaticText *player_sum_text = new wxStaticText(game_info_panel, wxID_ANY,
                                               "Player Sum:");

  sum_counter = new wxStaticText(game_info_panel, wxID_ANY, ""); 

   wxStaticText *dealer_sum_text = new wxStaticText(game_info_panel, wxID_ANY,
                                               "Dealer Sum:");

  dealer_sum = new wxStaticText(game_info_panel, wxID_ANY, ""); 
  wxStaticText *winner_type_text = new wxStaticText(game_info_panel, wxID_ANY,
                                               "Winner:");
  winner_text = new wxStaticText(game_info_panel, wxID_ANY, ""); 
  game_type = new wxStaticText(game_info_panel, wxID_ANY, ""); 
  game_type->SetForegroundColour(wxColor(255,0,0));
   wxFont t_Font = game_type->GetFont();
    t_Font.SetPointSize( 20 );
    game_type->SetFont(t_Font);


  game_info_sizer->Add(wins_text, 0, wxALIGN_RIGHT, 0);
  game_info_sizer->Add(wins_counter, 0, 0, 0);
  game_info_sizer->AddSpacer(20);
  game_info_sizer->Add(loss_text, 0, wxALIGN_RIGHT, 0);
  game_info_sizer->Add(loss_counter, 0, 0, 0);
  game_info_sizer->AddSpacer(20);
  game_info_sizer->Add(cash_text, 0, wxALIGN_RIGHT, 0);
  game_info_sizer->Add(cash_counter, 0, 0, 0);
  game_info_sizer->AddSpacer(20);
  game_info_sizer->Add(bet_text, 0, wxALIGN_RIGHT, 0);
  game_info_sizer->Add(bet_counter, 0, 0, 0);
  game_info_sizer->AddSpacer(20);
  game_info_sizer->Add(player_sum_text, 0, wxALIGN_RIGHT, 0);
  game_info_sizer->Add(sum_counter, 0, 0, 0);
  game_info_sizer->AddSpacer(20);
  game_info_sizer->Add(dealer_sum_text, 0, wxALIGN_RIGHT, 0);
  game_info_sizer->Add(dealer_sum, 0, 0, 0);
  game_info_sizer->AddSpacer(20);
  game_info_sizer->Add(winner_type_text, 0, wxALIGN_RIGHT, 0);
  game_info_sizer->Add(winner_text, 0, 0, 0);
  game_info_sizer->AddSpacer(20);
  game_info_sizer->Add(game_type, 0, 0, 0);
  game_info_panel->SetForegroundColour(wxColor(255,255,255));
  game_info_panel->SetSizer(game_info_sizer);

 
}
void ButtonPanel::Dealer_panel(vector<wxPanel *> panels,wxSizer* sizer)
{
    
  for (wxPanel* panel : panels)
  {
   
    sizer->Add(panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(15);
  
  }
}


void ButtonPanel::AddSubPanelsToMainPanel(vector<wxPanel *> panels,wxSizer* sizer)
{
    
  for (wxPanel* panel : panels)
  {
   
    sizer->Add(panel, 0, wxALIGN_CENTER, 0);
     sizer->AddSpacer(15);
  
  }
}

void ButtonPanel::EnterName(wxCommandEvent& event)
{
    Message = (const char *) wxGetTextFromUser( wxT("Enter your Name:"), wxT("Your Name" )).mb_str(wxConvUTF8);
    player.setName(Message);
    player_text->SetLabelText(Message);
    
}

void ButtonPanel::on_new_Game(wxCommandEvent& event)
{
    wxPNGHandler *handler = new wxPNGHandler;
    wxImage::AddHandler(handler);
    wxStaticBitmap *image;
    image = new wxStaticBitmap( this, wxID_ANY, wxBitmap("back_of_card.jpg", wxBITMAP_TYPE_ANY), wxPoint(0,50), wxSize(100, 150));
    image = new wxStaticBitmap( this, wxID_ANY, wxBitmap("back_of_card.jpg", wxBITMAP_TYPE_ANY), wxPoint(30,50), wxSize(100, 150));
    image = new wxStaticBitmap( this, wxID_ANY, wxBitmap("back_of_card.jpg", wxBITMAP_TYPE_ANY), wxPoint(60,50), wxSize(100, 150));
    image = new wxStaticBitmap( this, wxID_ANY, wxBitmap("back_of_card.jpg", wxBITMAP_TYPE_ANY), wxPoint(90,50), wxSize(100, 150));
    image = new wxStaticBitmap( this, wxID_ANY, wxBitmap("back_of_card.jpg", wxBITMAP_TYPE_ANY), wxPoint(120,50), wxSize(100, 150));
    image = new wxStaticBitmap( this, wxID_ANY, wxBitmap("back_of_card.jpg", wxBITMAP_TYPE_ANY), wxPoint(150,50), wxSize(100, 150));
    image = new wxStaticBitmap( this, wxID_ANY, wxBitmap("back_of_card.jpg", wxBITMAP_TYPE_ANY), wxPoint(180,50), wxSize(100, 150));
    image = new wxStaticBitmap( this, wxID_ANY, wxBitmap("back_of_card.jpg", wxBITMAP_TYPE_ANY), wxPoint(210,50), wxSize(100, 150));
    

    image = new wxStaticBitmap( this, wxID_ANY, wxBitmap("back_of_card.jpg", wxBITMAP_TYPE_ANY), wxPoint(0,260), wxSize(100, 150));
    image = new wxStaticBitmap( this, wxID_ANY, wxBitmap("back_of_card.jpg", wxBITMAP_TYPE_ANY), wxPoint(30,260), wxSize(100, 150));
    image = new wxStaticBitmap( this, wxID_ANY, wxBitmap("back_of_card.jpg", wxBITMAP_TYPE_ANY), wxPoint(60,260), wxSize(100, 150));
    image = new wxStaticBitmap( this, wxID_ANY, wxBitmap("back_of_card.jpg", wxBITMAP_TYPE_ANY), wxPoint(90,260), wxSize(100, 150));
    image = new wxStaticBitmap( this, wxID_ANY, wxBitmap("back_of_card.jpg", wxBITMAP_TYPE_ANY), wxPoint(120,260), wxSize(100, 150));
    image = new wxStaticBitmap( this, wxID_ANY, wxBitmap("back_of_card.jpg", wxBITMAP_TYPE_ANY), wxPoint(150,260), wxSize(100, 150));
    image = new wxStaticBitmap( this, wxID_ANY, wxBitmap("back_of_card.jpg", wxBITMAP_TYPE_ANY), wxPoint(180,260), wxSize(100, 150));
    image = new wxStaticBitmap( this, wxID_ANY, wxBitmap("back_of_card.jpg", wxBITMAP_TYPE_ANY), wxPoint(210,260), wxSize(100, 150));

    sum_counter->SetLabelText(std::to_string(0));
    dealer_sum->SetLabelText(std::to_string(0));
    bet_counter->SetLabelText(std::to_string(0));
    cash_counter->SetLabelText(std::to_string(game.player_cash()));
    winner_text->SetLabelText("");
    game_type->SetLabelText("");
    
    SetStartMenuVisibility(false);
    SetOptionsVisibility(true);
    SetGameVisibility(false);
 
}

void ButtonPanel::on_exit(wxCommandEvent& event)
{
    exit(0);
}

void ButtonPanel::on_play_game(wxCommandEvent& event)
{
    SetOptionsVisibility(false);

    game.sGame();
    vector <char> asd = game.player_cards();
    vector <char> bsd = game.player_suits();
    
    
    for(int i = 0; i< asd.size();i++)
    {

    string sss = card.card_info(bsd[i],asd[i]);
    
    wxPNGHandler *handler = new wxPNGHandler;
    wxImage::AddHandler(handler);
    wxStaticBitmap *image;
    image = new wxStaticBitmap( this, wxID_ANY, wxBitmap(sss, wxBITMAP_TYPE_PNG), wxPoint(0+i*30,50), wxSize(100, 150));

    }
    SetStartMenuVisibility(false);
    SetGameVisibility(true);
    if(game.get_sum() >21 || game.get_sum() ==21|| game.get_dealer_sum() > 21 || game.get_dealer_sum()== 21)
    {
        dealer_game();

    }
    flag = true;
    get_info(flag);
}

void ButtonPanel::on_hit(wxCommandEvent& event)
{
    
    
    game.hit_case();
    
    vector <char> asd = game.player_cards();
    vector <char> bsd = game.player_suits();
    
    for(int i = 2; i< asd.size();i++)
    {

    string sss = card.card_info(bsd[i],asd[i]);
    
    wxPNGHandler *handler = new wxPNGHandler;
    wxImage::AddHandler(handler);
    wxStaticBitmap *image;
    image = new wxStaticBitmap( this, wxID_ANY, wxBitmap(sss, wxBITMAP_TYPE_PNG), wxPoint(60+(i-2)*50,50), wxSize(100, 150));

    }
    if(game.get_sum() >21 || game.get_sum() ==21|| game.get_dealer_sum() > 21 || game.get_dealer_sum()== 21)
    {
       
       dealer_game();

    }
    bool flag = true;
    get_info(flag);
 
}

void ButtonPanel::on_stand(wxCommandEvent& event)
{
   
   dealer_game();

}

void ButtonPanel::update_button_choice_text(const Choice choice)
{
    chosen_button_name->SetLabelText(choice_to_wxString(choice));
}

void ButtonPanel::on_deal_card(wxCommandEvent& event)
{
    
    wxPNGHandler *handler = new wxPNGHandler;
    wxImage::AddHandler(handler);
    wxStaticBitmap *image;
    image = new wxStaticBitmap( this, wxID_ANY, wxBitmap("Cards/back_of_card.png", wxBITMAP_TYPE_PNG), wxPoint(0,200), wxSize(100, 150));

    wxPNGHandler *handler1 = new wxPNGHandler;
    wxImage::AddHandler(handler1);
    wxStaticBitmap *image1;
    image1 = new wxStaticBitmap( this, wxID_ANY, wxBitmap("Cards/back_of_card.png", wxBITMAP_TYPE_PNG), wxPoint(20,200), wxSize(100, 150));

    wxPNGHandler *handler2 = new wxPNGHandler;
    wxImage::AddHandler(handler2);
    wxStaticBitmap *image2;
    image2 = new wxStaticBitmap( this, wxID_ANY, wxBitmap("Cards/back_of_card.png", wxBITMAP_TYPE_PNG), wxPoint(40,200), wxSize(100, 150));
    
}

void ButtonPanel::on_show_card(wxCommandEvent& event)
{
    wxPNGHandler *handler = new wxPNGHandler;
    wxImage::AddHandler(handler);
    wxStaticBitmap *image;
    image = new wxStaticBitmap( this, wxID_ANY, wxBitmap("Cards/back_of_card.png", wxBITMAP_TYPE_PNG), wxPoint(0,100), wxSize(100, 150));

    wxPNGHandler *handler1 = new wxPNGHandler;
    wxImage::AddHandler(handler1);
    wxStaticBitmap *image1;
    image1 = new wxStaticBitmap( this, wxID_ANY, wxBitmap("Cards/back_of_card.png", wxBITMAP_TYPE_PNG), wxPoint(20,100), wxSize(100, 150));

    wxPNGHandler *handler2 = new wxPNGHandler;
    wxImage::AddHandler(handler2);
    wxStaticBitmap *image2;
    image2 = new wxStaticBitmap( this, wxID_ANY, wxBitmap("Cards/back_of_card.png", wxBITMAP_TYPE_PNG), wxPoint(40,100), wxSize(100, 150));
    
}

void ButtonPanel::on_increase(wxCommandEvent& event)
{
    if(game.player_cash() == 0)
    {
        SetGameVisibility(false);
        game_type->SetLabelText("You are Broke");
        cout << "Broke!" << endl;
    }
    game.startBet(87);
    flag = false;
    get_info(flag);
    
}

void ButtonPanel::on_decrease(wxCommandEvent& event)
{
    if(game.player_cash() == 0)
    {
        SetGameVisibility(false);
        game_type->SetLabelText("You are Broke");
    }
    game.startBet(83);
    flag = false;
    get_info(flag);
    
}

void ButtonPanel::on_done(wxCommandEvent& event)
{
    game_type->SetLabelText("Enter bet");
    cout << game.get_bet() << endl;
    if(game.get_bet() != 0)
    {
        SetStartMenuVisibility(true);
        SetGameVisibility(false);
        game_type->SetLabelText("");
    }
    else if(game.player_cash() == 0)
    {
        game_type->SetLabelText("You are Broke");
    }
}

void ButtonPanel::dealer_game()
{
    game.beginGame();
    
    
    vector <char> asd = game.dealer_cards();
    vector <char> bsd = game.dealer_suits();
    
    for(int i = 0; i< asd.size();i++)
    {

    string sss = card.card_info(bsd[i],asd[i]);
    
    wxPNGHandler *handler = new wxPNGHandler;
    wxImage::AddHandler(handler);
    wxStaticBitmap *image;
    image = new wxStaticBitmap( this, wxID_ANY, wxBitmap(sss, wxBITMAP_TYPE_PNG), wxPoint(0+i*30,260), wxSize(100, 150));

    }
    string a = game.check_sum();
    
    game_type->SetLabelText(a);
    
    SetGameVisibility(false);
    
    dealer_sum->SetLabelText(to_string(game.get_dealer_sum()));
    winner_text->SetLabelText(game.displayWinner());
    flag = true;
    get_info(flag);

}

void ButtonPanel::get_info(bool check)
{
    int sum = 0;
    int wins = game.player_wins();
    int loses = game.player_loses();
    int cash = game.player_cash();
    int bet = game.get_bet();
    if(check){
        sum = game.get_sum();
    }
    

    wins_counter->SetLabelText(std::to_string(wins));
    loss_counter->SetLabelText(std::to_string(loses));
    cash_counter->SetLabelText(std::to_string(cash));
    bet_counter->SetLabelText(std::to_string(bet));
    
    sum_counter->SetLabelText(std::to_string(sum));
   


    
}