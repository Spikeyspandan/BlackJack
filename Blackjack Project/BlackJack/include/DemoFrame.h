#ifndef DEMOFRAME_H_
#define DEMOFRAME_H_

#include "ButtonPanel.h"

/**
 * The application frame.
 */
class DemoFrame : public wxFrame
{
public:
    void OnPaint(wxPaintEvent & event);
    /**
     * Constructor.
     * @param title the window title.
     */
    DemoFrame(const wxString& title);

    /**
     * Destructor.
     */
    virtual ~DemoFrame();

    /**
     * Event handler for the About menu item.
     * @param event the item selection event.
     */
    void on_about(wxCommandEvent& event);

    /**
     * Event handler for the Quit menu item.
     * @param event the item selection event.
     */
    void on_quit(wxCommandEvent& event);

private:
    // The event table that maps events to their handlers.
    wxDECLARE_EVENT_TABLE();
    
    ButtonPanel *button_panel;
    void init();
    void init_sizer();
    void init_menu_bar();
};

// IDs for the menu commands.
enum
{
    RPS_About = wxID_ABOUT,
    RPS_Quit  = wxID_EXIT
};

#endif /* DEMOFRAME_H_ */
