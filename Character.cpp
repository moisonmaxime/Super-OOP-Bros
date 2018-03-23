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
    this->jumpTime = 0;
    this->frame = Frame(0.0, 0.0, .05, .10);
    this->hitbox = Frame(0.0, 0.0, .04, .09);
}

Character::Character(float x, float y){
    this->x = x;
    this->y = y;
    this->vx = 0;
    this->vy = 0;
    this->jumpTime = 0;
    this->frame = Frame(x, y, .15, .3);
    this->hitbox = Frame(x+.1, y-.05, .13, .3);
    //this->frame = Frame(x, y, .05, .10);
    //this->hitbox = Frame(x, y, .04, .09);
}

void Character::setPosition(float x, float y){
    this->x = x;
    this->y = y;
}

void Character::setVelocity(float vx, float vy){
    this->vx = vx;
    this->vy = vy;
}

void Character::setVX(float vx){
    this->vx = vx;
}

void Character::setVY(float vy){
    this->vy = vy;
}


void Character::jump() {
    if (vy >= 0 && vy <= 0.1 && jumpTime <= 10) {
        vy += 0.05;
    } else if (vy <= 0.1 && jumpTime > 10) {
        jumpTime = 0;
    }
    jumpTime++;
}

void Character::move(Direction direction) {
    if (vx <= 0.03 && vx >= -0.03) {
        vx += direction * 0.01;
    }
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
    
    this->x += vx;
    this->y += vy;
    
    if (this->y <= -1) {
        this->y = -1;
        this->vy = 0;
    }
    if (this->y >= 1-frame.getHeight()) {
        this->y = 1-frame.getHeight();
        this->vy = 0;
    }
    
    if (this->x <= -1) {
        this->x = -1;
        this->vx = 0;
    }
    if (this->x >= 1-frame.getWidth()) {
        this->x = 1-frame.getWidth();
        this->vx = 0;
    }
    
    // update frames
    this->frame.setX(x);
    this->hitbox.setX(x);
    this->frame.setY(y);
    this->hitbox.setY(y);
}

void Character::draw() {
    frame.draw();
}
