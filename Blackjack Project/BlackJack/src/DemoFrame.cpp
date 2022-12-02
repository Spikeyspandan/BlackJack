#include "DemoFrame.h"
#include <map>
#include <string>
#include <iostream>
#define         X_SIZE 30
#define         Y_SIZE 20
// The event table.
wxBEGIN_EVENT_TABLE(DemoFrame, wxFrame)
EVT_MENU(RPS_About, DemoFrame::on_about)
EVT_MENU(RPS_Quit,  DemoFrame::on_quit)
wxEND_EVENT_TABLE()

const int SIDE_MARGINS = 40;

DemoFrame::DemoFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title), button_panel(new ButtonPanel(this)){
    init();
    this->Connect(wxEVT_PAINT, wxPaintEventHandler(DemoFrame::OnPaint));
    wxSize size = GetSize();
    size.SetHeight (950);
    size.SetWidth (800 );
    SetSize(size);
    
    

}
void DemoFrame::OnPaint(wxPaintEvent & event)
{
  wxPaintDC dc(this);
  
  wxBitmap bmp("blackjack_background.png",wxBITMAP_TYPE_ANY);
  wxImage img=bmp.ConvertToImage();
    img.Rescale(1888,1100);
    
    dc.DrawBitmap(img,wxPoint(0,0));
 
}

DemoFrame::~DemoFrame()
{
    delete button_panel;
}

void DemoFrame::init()
{
    
    init_menu_bar();
    init_sizer();
    Layout();
 
}

void DemoFrame::init_sizer()
{
    wxSizer *frame_sizer = new wxBoxSizer(wxVERTICAL);

    frame_sizer->AddSpacer(20);
    
    frame_sizer->Add(button_panel, wxSizerFlags(0).Center());
   
    SetSizerAndFit(frame_sizer);
}

void DemoFrame::init_menu_bar()
{
    wxMenu *fileMenu = new wxMenu;
    fileMenu->Append(RPS_Quit,  "E&xit\tAlt-X", "Quit program");

    wxMenu *helpMenu = new wxMenu;
    helpMenu->Append(RPS_About, "&About\tF1",   "Show about dialog");

    wxMenuBar *menuBar = new wxMenuBar();
    menuBar->Append(fileMenu, "&File");
    menuBar->Append(helpMenu, "&Help");
    SetMenuBar(menuBar);
}

void DemoFrame::on_about(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox(wxString::Format(
                    "This is a BlackJack Game\n"
                    "built by CMPE 135 students:\n\n"
                    "Gil Abarca Ramos\n"
                    "Spandan Khatiwada\n"
                    "Alex Lujan \n"
                    "John Allen Bautista\n\n\n"
                    "Enjoy the Game.!!!"
                    
                    
                ),
                "BlackJack Game",
                wxOK | wxICON_INFORMATION,
                this);
}

void DemoFrame::on_quit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);  // true is to force the frame to close
}
