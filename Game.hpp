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
#include "Counter.hpp"
#include "PowerUP_Slow.hpp"
#include "PowerUP_Bullet.hpp"
#include "PowerUP_Roids.hpp"

using namespace std;

class Game{
protected:
    int frame;
    Pipe* lastPipe;
    vector<Pipe*> pipes;
    vector<PowerUP*> powerups;
    PhysicsController* physics;
    Background* bg;
    Ground* gr;
    bool isPlaying;
    void endGame();
    Counter* counter;
    
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
