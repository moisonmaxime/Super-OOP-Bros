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
#include "PowerUP_Slow.hpp"

using namespace std;

class Game{
protected:
    int frame;
    int score = 0;
    int maxScore = 0;
    Pipe* lastPipe;
    vector<Pipe*> pipes;
    vector<PowerUP*> powerups;
    PhysicsController* physics;
    Background* bg;
    Ground* gr;
    bool isPlaying;
    bool powerupEnabled;
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
