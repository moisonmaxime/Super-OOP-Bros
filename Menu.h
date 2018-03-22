 #ifndef MENU_H
 #define MENU_H

#include <vector>
#include "Game.h"
#include "Rect.h"

using namespace std;

class Menu{

  vector<Rect*> buttons;

public:

  Menu(bool isFirstGame){

    vector<Rect*> buttons;

    // button is (x, y, w, h, text)
    Rect b1 = Rect(-0.33f, 0.3f, 0.3f, 0.15f);
    Rect b2 = Rect(0.03f, 0.3f, 0.3f, 0.15f);

    if (isFirstGame){
      // todo: First game
      b1.setText("Play");
    }
    else{
      // todo: not 1st Game
      b1.setText("Play Again");
    }

    buttons.push_back(&b1);
    buttons.push_back(&b2);

  }

  // Draw the Menu (this is called from app.cpp)
  void draw(){

  }

};

 #endif
