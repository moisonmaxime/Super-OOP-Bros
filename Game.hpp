#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Character.hpp"
#include "PhysicsController.hpp"

using namespace std;

class Game{
    int frame;
    bool* keyStates;
    Character* player;
    PhysicsController* physics;
public:
    Game();
    void keyDown(int key);
    void keyUp(int key);
    void calculateNextFrame();
    void draw();
};

#endif
