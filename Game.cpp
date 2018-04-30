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

void advanceAnimation(int i){
    //if (!singleton->player->done()){
        singleton->player->advance();
        glutPostRedisplay();
        glutTimerFunc(32, advanceAnimation, i);
    std::cout << "test" << std::endl;
    //}
}

Game::Game() {
    singleton = this; 
    frame = 0;
    bg = new Background("images/bg.bmp");
    physics = new PhysicsController(GRAVITY);
    player = new Character(-0.5, 0.6);
    speed = DEFAULT_SPEED;
    pipes.push_back(new Pipe(0, 0.4, 0.6));
}

void Game::jumpPress() {
    player->jump();
}

void Game::calculateNextFrame() {
    physics->applyforces(player);
    player->calculateNextFrame();
    player->advance();
//    for (auto it = objects.cbegin(); it != objects.cend(); it++)
//        player->handleCollisionWith(*it);
}

void Game::draw(){
    calculateNextFrame();
    frame++;
    if (frame == 31){ frame = 0; }
    bg->draw();
    for (auto it = pipes.cbegin(); it != pipes.cend(); it++)
        (*it)->draw();
    player->draw();
    bg->incProgress(speed);
}
