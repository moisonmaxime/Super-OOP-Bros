//
//  Character.cpp
//  SuperOOPBros
//
//  Created by Maxime Moison on 3/22/18.
//  Copyright © 2018 Maxime Moison. All rights reserved.
//
#include "Character.hpp"

Character::Character(){
    this->vx = 0;
    this->vy = 0;
    this->jumpTime = 0;
    this->frame = Frame(0.0, 0.0, .1, .2);
    this->frame = Frame(0.0, 0.0, .1, .2);
}

Character::Character(float x, float y){
    this->vx = 0;
    this->vy = 0;
    this->jumpTime = 0;
    this->frame = Frame(x, y, .1, .2);
    this->frame = Frame(x, y, .1, .2);
}

void Character::setPosition(float x, float y){
    this->frame.x = x;
    this->frame.y = y;
    this->hitbox.x = x;
    this->hitbox.y = y;
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
    if (vy >= 0 && jumpTime <= 10) {
        vy = 0.07;
    }
    jumpTime++;
}

void Character::move(Direction direction) {
    if (vx <= 0.02 && vx >= -0.02) {
        vx += direction * 0.01;
    }
}

void Character::attack(){
    // todo
}

void Character::die(){
    // todo
}

Frame Character::getHitbox() {
    return this->frame;
}

bool Character::collidesWith(Object *other) {
    return this->frame.collidesWith(other->getHitbox());
}

float Character::getX(){ return this->frame.x; }
float Character::getY(){ return this->frame.y; }
float Character::getVX(){ return this->vx; }
float Character::getVY(){ return this->vy; }

void Character::calculateNextFrame() {
    // implement velocity handling
    float x = this->frame.x;
    float y = this->frame.y;
    
    x += vx;
    y += vy;
    
    if (y <= -1) {
        y = -1;
        vy = 0;
        jumpTime = 0; // Put in function called touch ground (:
    }
    if (y >= 1-frame.height) {
        y = 1-frame.height;
        vy = 0;
    }
    
    if (x <= -1) {
        x = -1;
        vx = 0;
    }
    if (x >= 1-frame.width) {
        x = 1-frame.width;
        vx = 0;
    }
    
    // update frames
    this->frame.x = x;
    this->frame.y = y;
    this->hitbox.x = x;
    this->hitbox.y = y;
}

void Character::draw() {
    frame.draw();
}
