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
    player = new Character(0.0, 0.0);
    physics = new PhysicsController(-0.005, -0.005);
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
    
    if (keyStates[32] && player->getVY() >= 0){
        player->jump();
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
