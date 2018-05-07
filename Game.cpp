//
//  Game.cpp
//  SuperOOPBros
//
//  Created by Maxime Moison on 3/22/18.
//  Copyright © 2018 Maxime Moison. All rights reserved.
//

#include "Game.hpp"
#include <iostream>

//#define DEFAULT_SPEED 0.01
//#define GRAVITY -0.002

static Game* singleton;

Game::Game() {
    singleton = this;
    frame = 0;
    bg = new Background("images/bg.bmp");
    gr = new Ground("ground.fw.bmp");
    physics = new PhysicsController(DEFAULT_GRAVITY);
    player = new Character("images/flappy2.png", "images/fireball.bmp", -0.5, 0.6);
    speed = DEFAULT_SPEED;
    pipes.push_back(new Pipe(1, 0.4, 0.6));
    pipes.push_back(new Pipe(2+WIDTH, 0.6, 0.6));
    pipes.push_back(new Pipe(3+WIDTH, -.5, 0.6));
    isPlaying = true;
}

void Game::jumpPress() {
    player->jump();
}

void Game::calculateNextFrame() {
    physics->applyforces(player);
    bg->incProgress(speed);
    gr->incProgress(speed);
    player->calculateNextFrame();
    if (player->getMinY() < -0.90)
        this->endGame();
    for (auto it = pipes.cbegin(); it != pipes.cend(); it++)
        (*it)->calculateNextFrame();
    for (auto it = pipes.cbegin(); it != pipes.cend(); it++)
        if ((*it)->collidesWith(player))
            this->endGame();
}

void Game::restart() {
    int i = 1;
    for (auto it = pipes.cbegin(); it != pipes.cend(); it++, i++)
        (*it)->setX((i+WIDTH));
    player->reset();
    isPlaying = true;
}

void Game::resume() {
    isPlaying = true;
    
}

void Game::pause() {
    isPlaying = false;
}

void Game::endGame() {
    player->die();
    isPlaying = false;
}

void Game::draw(){
    if (isPlaying) {
        calculateNextFrame();
        bg->draw();
        for (auto it = pipes.cbegin(); it != pipes.cend(); it++)
            (*it)->draw();
        player->draw();
        gr->draw();
        bg->incProgress(speed);
        gr->incProgress(speed);
    } else {
        bg->draw();
        for (auto it = pipes.cbegin(); it != pipes.cend(); it++)
            (*it)->draw();
        player->draw();
        gr->draw();
        
    }
}
