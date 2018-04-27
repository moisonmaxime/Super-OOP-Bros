#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include "Character.hpp"
#include "Box.hpp"
#include "PhysicsController.hpp"
#include "Background.hpp"
#include "GlutApp.hpp"

using namespace std;

class Game{
    int frame;
    bool* keyStates;
    PhysicsController* physics;
    vector<Box*> objects;
    Background* bg;
    float speed;
    
public:
    Game();
    Character* player;
    void jumpPress();
    void calculateNextFrame();
    void draw();
};

#endif
