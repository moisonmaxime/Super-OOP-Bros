//
//  Game.cpp
//  SuperOOPBros
//
//  Created by Maxime Moison on 3/22/18.
//  Copyright © 2018 Maxime Moison. All rights reserved.
//

#include "Game.hpp"

Game::Game(){
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

void Game::draw(){
    
    for (int i=0; i<256; i++) {
        if (keyStates[i]) {
            cout << "Key " << i << " is being pressed" << endl;
        }
    }
    
    //cout << "Frame " << frame << endl;
    frame++;
    if (frame == 11){ frame = 0; }
}
