#include "ButtonDemo.h"
#include "DemoFrame.h"

// Create a new application object.
wxIMPLEMENT_APP(ButtonDemo);

bool ButtonDemo::OnInit()
{
    if (!wxApp::OnInit()) return false;

    DemoFrame *frame = new DemoFrame("Blackjack");
    frame->Show(true);

    return true;
}
