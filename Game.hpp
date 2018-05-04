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
    bool isPlaying;
    
    void endGame();
public:
    Game();
    Character* player;
    void jumpPress();
    void calculateNextFrame();
    void resume();
    void pause();
    void draw();
};

#endif
