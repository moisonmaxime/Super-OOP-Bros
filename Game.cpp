//
//  Game.cpp
//  SuperOOPBros
//
//  Created by Maxime Moison on 3/22/18.
//  Copyright © 2018 Maxime Moison. All rights reserved.
//

#include "Game.hpp"
#include <iostream>

Game::Game(){
    frame = 0;
    bg = new Background("bg.bmp");
    physics = new PhysicsController(-0.005, -0.005);
    player = new Character(0.0, -.8);
    objects.push_back(new Box(-1, -1, 0.12, 0.24));
    objects.push_back(new Box(0, 0, 0.12, 0.24));
    objects.push_back(new Box(0.5, 0.5, 0.12, 0.24));
    objects.push_back(new Box(-1, 0.5, 0.12, 0.24));
    objects.push_back(new Box(-0.5, 0.25, 0.12, 0.24));
    objects.push_back(new Box(0.5, -1.15, 0.12, 0.24));
    objects.push_back(new Box(-1, -1.25, 2, 0.27));
    keyStates = new bool[256];
    for (int i=0; i<256; i++) {
        keyStates[i] = false;
    }
    speed = .01;
}

void Game::keyDown(int key) {
    keyStates[key] = true;
    if (key == 3) {
        exit(0);
    }
}

void Game::keyUp(int key) {
    keyStates[key] = false;
}

void Game::calculateNextFrame() {
    
    if (keyStates[100]){
        player->move(Direction::Right);
    }
    if (keyStates[97]){
        player->move(Direction::Left);
    }
    
    if (keyStates[32]){
        player->jump();
    }
    
    if (keyStates[114]) {
        player->setPosition(0, 0);
    }
    
    physics->applyforces(player);
    player->calculateNextFrame();
    for (auto it = objects.cbegin(); it != objects.cend(); it++)
        player->handleCollisionWith(*it);
}

void Game::draw(){
    for (auto it = objects.cbegin(); it != objects.cend(); it++)
        (*it)->draw();
    player->draw();
    calculateNextFrame();
    frame++;
    if (frame == 31){ frame = 0; }
    bg->draw();
    bg->incProgress(speed);
}
