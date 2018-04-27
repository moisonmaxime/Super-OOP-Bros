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
    this->hitbox = Frame(0.0, 0.0, .1, .2);
    this->texture = new TexRect("flappy.bmp", "fireball.bmp", 6, 6, &(this->frame.x), &(this->frame.y), &(this->frame.width), &(this->frame.height));
    this->dead = false;
}

Character::Character(float x, float y){//add filename todo
    this->vx = 0;
    this->vy = 0;
    this->jumpTime = 0;
    this->frame = Frame(x, y, .1, .2);
    this->hitbox = Frame(x, y, .1, .2);
    this->texture = new TexRect("flappy.bmp", "fireball.bmp", 6, 6, &(this->frame.x), &(this->frame.y), &(this->frame.width), &(this->frame.height));
    this->dead = false;
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
    vy = 0.07;
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
    this->dead = true;
    texture->explode(this->texture);
}

Frame Character::getHitbox() {
    return this->hitbox;
}

bool Character::collidesWith(Object *other) {
    return hitbox.collidesWith(other->getHitbox());
}

void Character::handleCollisionWith(Object *other) {
    if (collidesWith(other)) {
        // Handle collision with object
    }
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
    
    // update frames
    this->frame.x = x;
    this->frame.y = y;
    this->hitbox.x = x;
    this->hitbox.y = y;
}

void Character::draw() {
    //frame.draw(); //this draws the hitbox
    texture->draw();
}
