//
//  Game.cpp
//  SuperOOPBros
//
//  Created by Maxime Moison on 3/22/18.
//  Copyright © 2018 Maxime Moison. All rights reserved.
//

#include "Game.hpp"
#include <stdio.h>
#include <iostream>

Game::Game(){
    player = new Character(0.0, 0.0);
    physics = new PhysicsController(-0.1, -1);
    frame = 0;
    keyStates = new bool[256];
    for (int i=0; i<256; i++) {
        keyStates[i] = false;
    }
}

void Game::keyDown(int key) {
    keyStates[key] = true;
    if (key == 3) {
        exit(0);
    }
    
    if (key == 107 && player->getY() == 0){
        player->setVY(1.0);
    }
}

void Game::keyUp(int key) {
    keyStates[key] = false;
}

void Game::calculateNextFrame() {
    
    if (keyStates[108]){
        player->setVX(.1);
    }
    if (keyStates[106]){
        player->setVX(-.1);
    }
    
    physics->applyforces(player);
    player->calculateNextFrame();
    /*
    for (int i=0; i<256; i++) {
        if (keyStates[i]) {
            cout << "Key " << i << " is being pressed" << endl;
        }

    }
     */
}

void Game::draw(){
    player->draw();
    calculateNextFrame();
    frame++;
    if (frame == 31){ frame = 0; }
}
