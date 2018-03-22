#ifndef GAME_H
#define GAME_H

#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Character.h"
#include "Gravity.h"
#include "Menu.h"

using namespace std;

class Game{
    vector<Character*> players;
    Gravity g;
    Character* winner;
    bool isFirstGame;
    int frame;

public:

  // Default game constructor
  Game(){
    g = Gravity(); // default gravity
    frame = 0;
  }

  // the Menu class will set players.
  void setCharacters(Character* p1, Character* p2){
    players.push_back(p1);
    players.push_back(p2);
  }

  void draw(){
    cout << "Frame " << frame << endl;
    frame++;
    if (frame == 11){ frame = 0; }
  }

};

#endif
