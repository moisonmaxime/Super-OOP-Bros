//
//  Game.cpp
//  SuperOOPBros
//
//  Created by Maxime Moison on 3/22/18.
//  Copyright © 2018 Maxime Moison. All rights reserved.
//

#include "Game.hpp"
#include <iostream>

#define DEFAULT_SPEED 0.01
#define GRAVITY -0.002

static Game* singleton;

Game::Game() {
    singleton = this;
    frame = 0;
    bg = new Background("images/bg.bmp");
    physics = new PhysicsController(GRAVITY);
    player = new Character(-0.5, 0.6);
    speed = DEFAULT_SPEED;
    isPlaying = true;
    pipes.push_back(new Pipe(0, 0.4, 0.6));
}

void Game::jumpPress() {
    player->jump();
}

void Game::calculateNextFrame() {
    physics->applyforces(player);
    bg->incProgress(speed);
    player->calculateNextFrame();
    if (player->getMinY() < -1)
        this->endGame();
    for (auto it = pipes.cbegin(); it != pipes.cend(); it++)
        (*it)->calculateNextFrame();
    for (auto it = pipes.cbegin(); it != pipes.cend(); it++)
        if ((*it)->collidesWith(player))
            this->endGame();
}

void Game::resume() {
    isPlaying = true;
}

void Game::pause() {
    isPlaying = false;
}

void Game::endGame() {
    isPlaying = false;
}

void Game::draw(){
    if (isPlaying) {
        calculateNextFrame();
//        frame++;                              // - Why do we need this ?
//        if (frame == 31){ frame = 0; }        //
        bg->draw();
        for (auto it = pipes.cbegin(); it != pipes.cend(); it++)
            (*it)->draw();
        player->draw();
    } else {
        bg->draw();
        for (auto it = pipes.cbegin(); it != pipes.cend(); it++)
            (*it)->draw();
        player->draw();
        
    }
}
