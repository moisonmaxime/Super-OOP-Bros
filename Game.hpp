#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include "Character.hpp"

#include "PhysicsController.hpp"
#include "Background.hpp"
#include "GlutApp.hpp"
#include "Pipe.hpp"
#include "AnimatedRect2.h"
#include "Ground.hpp"

using namespace std;

class Game{
    int frame;
    PhysicsController* physics;
    Background* bg;
    float speed;
    Ground* gr;
    vector<Pipe*> pipes;
    Character* player;
    
public:
    Game();
    void jumpPress();
    void calculateNextFrame();
    void draw();
    void loop();
};

#endif
