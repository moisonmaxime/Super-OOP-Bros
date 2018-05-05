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
#include "PowerUP.hpp"

using namespace std;

class Game{
    int frame;
    vector<Pipe*> pipes;
    vector<PowerUP*> powerups;
    PhysicsController* physics;
    Background* bg;
    Ground* gr;
    float speed;
    bool isPlaying;
    float gameSpeed;
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
