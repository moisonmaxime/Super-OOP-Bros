#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include "Character.hpp"

#include "PhysicsController.hpp"
#include "Background.hpp"
#include "GlutApp.hpp"
#include "Pipe.hpp"

using namespace std;

class Game{
    int frame;
    vector<Pipe*> pipes;
    PhysicsController* physics;
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
