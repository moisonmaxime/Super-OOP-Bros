//
//  Game.cpp
//  SuperOOPBros
//
//  Created by Maxime Moison on 3/22/18.
//  Copyright © 2018 Maxime Moison. All rights reserved.
//

#include "Game.hpp"
#include <iostream>
#include <ctime>

#define DEFAULT_SPEED 0.01
#define GRAVITY -0.002

#define RAND_MAX 0x7fffffff

static Game* singleton;

void advanceAnimation(int i){
    //if (!singleton->player->done()){
    
        singleton->pipes[0]->move();
//        singleton->player->advance();
//        glutPostRedisplay();
        glutTimerFunc(32, advanceAnimation, i);
    //std::cout << "test" << std::endl;
    //}
}

Game::Game() {
    singleton = this; 
    frame = 0;
    bg = new Background("images/bg.bmp");
    physics = new PhysicsController(GRAVITY);
    player = new Character(-0.5, 0.6);
    speed = DEFAULT_SPEED;
    
    double fr;
    double x = 0.0;
    
    //Create Tubes
    for(int i = 2; i < 100; i++) {
        fr = (double)rand() / RAND_MAX;
        if(fr >= .7) {
            fr = fr - 0.3;
        }
        if (i % 2 == 0) {
            fr = fr * -1;
        }
        pipes.push_back(new Pipe(i, fr, 0.5));
    }
    
    //Create Ground
    for(int i = -1; i < 100; i++) {
        ground.push_back(new TexRect("ground.fw.bmp", 1, 1, i, -.95, 2, .2));
    }
    
    //Mushroom PowerDown
    for(int i = 0; i < 5; i++) {
        x += 1.5;
        mushroom.push_back(new AnimatedRect2("images/mushroom.png", 1, 1, x, .5, .15, .2));
    }
}


void Game::jumpPress() {
    player->jump();
}

void Game::calculateNextFrame() {
    physics->applyforces(player);
    player->calculateNextFrame();
    player->advance();
//    for (auto it = Object.cbegin(); it != Object.cend(); it++)
//        player->handleCollisionWith(*it);
}

void Game::draw(){
    calculateNextFrame();
    frame++;
    if (frame == 31){ frame = 0; }
    bg->draw();

    
    for (auto it = pipes.cbegin(); it != pipes.cend(); it++) {
        (*it)->draw();
        (*it)->move();
    }
    player->draw();
    bg->incProgress(speed);
    for(int i = 0; i < 100; i++) {
        ground[i]->draw();
        ground[i]->incY();
    }
    
    for(int i = 0; i < 5; i++) {
        mushroom[i]->draw();
        mushroom[i]->incY();
    }
}
