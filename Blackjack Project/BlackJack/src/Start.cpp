#include "Start.h"

wxString move_to_wxString(Start choice)
{
    switch (choice)
    {
        case Start::NEW_GAME :      return "New Game";
        case Start::PLAY_GAME:      return "Play Game";
        case Start::EXIT:        return "Exit";
        default:                    return "none";
    }
}