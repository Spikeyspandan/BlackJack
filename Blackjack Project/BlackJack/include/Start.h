#ifndef START_H_
#define START_H_

#include "wx/wx.h"

using namespace std;

enum class Start
{
  NEW_GAME,
  PLAY_GAME,
  EXIT,
  ERROR,
};

static const Start options_list[] =
    {
        Start::NEW_GAME,
        Start::PLAY_GAME,
        Start::EXIT,
    };

wxString move_to_wxString(Start choice);
#endif