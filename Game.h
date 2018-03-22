#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Character.h"
#include "Gravity.h"
#include "Menu.h"

using namespace std;

class Game{
    vector<Character*> players;
    Gravity g;
    Character* winner;
    bool isFirstGame;

public:

  // Default game constructor
  Game(){
    g = Gravity(); // default gravity
  }

  // the Menu class will set players.
  void setCharacters(Character* p1, Character* p2){
    players.push_back(p1);
    players.push_back(p2);
  }

  void draw(){

  }

};

#endif
