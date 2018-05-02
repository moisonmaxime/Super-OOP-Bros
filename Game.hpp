#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include "Character.hpp"

#include "PhysicsController.hpp"
#include "Background.hpp"
#include "GlutApp.hpp"
#include "Pipe.hpp"
#include "TexRect.h"
#include "AnimatedRect2.h"

using namespace std;

class Game{
    int frame;
    PhysicsController* physics;
    Background* bg;
    float speed;
    Background* gr;
    
public:
    Game();
    vector<Pipe*> pipes;
    vector<TexRect*> ground;
    vector<AnimatedRect2*> mushroom;
    Character* player;
    void jumpPress();
    void calculateNextFrame();
    void draw();
    void loop();
};

#endif
