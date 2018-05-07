#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include "Character.hpp"

#include "PhysicsController.hpp"
#include "Background.hpp"
#include "GlutApp.hpp"
#include "Pipe.hpp"
#include "Ground.hpp"

using namespace std;

class Game{
    int frame;
    int score;
    Pipe* lastPipe;
    vector<Pipe*> pipes;
    PhysicsController* physics;
    Background* bg;
    Ground* gr;
    float speed;
    bool isPlaying;
    
    void endGame();
public:
    Game();
    Character* player;
    void jumpPress();
    void calculateNextFrame();
    void restart();
    void resume();
    void pause();
    void draw();
};

#endif
