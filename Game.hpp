#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include "Character.hpp"
#include "Box.hpp"
#include "PhysicsController.hpp"

using namespace std;

class Game{
    int frame;
    bool* keyStates;
    Character* player;
    PhysicsController* physics;
    vector<Box*> objects;
public:
    Game();
    void keyDown(int key);
    void keyUp(int key);
    void calculateNextFrame();
    void draw();
};

#endif
