#include "Choice.h"

wxString choice_to_wxString(Choice choice)
{
    switch (choice)
    {
        case HIT:       return "Hit    ";
        case STAND:     return "Stand   ";
        case INC:       return "Increase";
        case DEC:       return "Decrease";
        case DONE:       return "Done";
        default:        return "none    ";
    }
}
