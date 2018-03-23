#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Character.hpp"

using namespace std;

class Game{
    int frame;
    bool* keyStates;
    Character* player;
public:
    Game();
    void keyDown(int key);
    void keyUp(int key);
    void calculateNextFrame();
    void draw();
    void applyGravity();
};

#endif
