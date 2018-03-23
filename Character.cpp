//
//  Character.cpp
//  SuperOOPBros
//
//  Created by Maxime Moison on 3/22/18.
//  Copyright © 2018 Maxime Moison. All rights reserved.
//
#include "Character.hpp"

Character::Character(){
    this->x = 0;
    this->y = 0;
    this->vx = 0;
    this->vy = 0;
    this->frame = Frame(0.0, 0.0, .05, .10);
    this->hitbox = Frame(0.0, 0.0, .04, .09);
}

Character::Character(float x, float y){
    this->x = x;
    this->y = y;
    this->vx = 0;
    this->vy = 0;
    this->frame = Frame(x, y, .15, .3);
    this->hitbox = Frame(x+.1, y-.05, .13, .3);
    //this->frame = Frame(x, y, .05, .10);
    //this->hitbox = Frame(x, y, .04, .09);
}

void Character::setPostion(int x, int y){
    this->x = x;
    this->y = y;
}

void Character::setVelocity(int vx, int vy){
    this->vx = vx;
    this->vy = vy;
}

void Character::setVX(float vx){
    this->vx = vx;
}

void Character::setVY(float vy){
    this->vy = vy;
}

void Character::attack(){
    // todo
}

void Character::die(){
    // todo
}

float Character::getX(){ return this->x; }
float Character::getY(){ return this->y; }
float Character::getVX(){ return this->vx; }
float Character::getVY(){ return this->vy; }

void Character::calculateNextFrame() {
    // implement velocity handling
    
    // X velocity
    if (vx != 0){
        if (vx > 1){ vx = 1.0; } // Max speed
        if (vx < -1){ vx = -1.0; } // Maxx speed
        if (vx > 0){ vx -= .05*vx; } //max dist
        if (vx < 0){ vx -= .05*vx; } //max dist
        x += vx*.05; // Finally adjust x
        vx -= vx*.1; // decrease velocity
        
        // update frames
        this->frame.setX(x);
        this->hitbox.setX(x);
    }
    
    // Y velocity
    if (vy != 0){
        if (y < 0){ vy = 0; y = 0; } // set VY == 0 (hits ground)
        if (vy > 0){ vy -= .01*vy; } //max dist
        if (vy < 0){ vy += .01*vy; } //max dist
        y += vy*.1; // Finally adjust y
        vy -= .05 + vy*vy*.1; // decrease velocity
        
        // update frames
        this->frame.setY(y);
        this->hitbox.setY(y);
    }
}

void Character::draw() {
    frame.draw();
}
