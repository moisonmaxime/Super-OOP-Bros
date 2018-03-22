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
}

Character::Character(float x, float y){
    this->x = x;
    this->y = y;
}

void Character::setPostion(int x, int y){
    this->x = x;
    this->y = y;
}

void Character::setVelocity(int vx, int vy){
    this->vx = vx;
    this->vy = vy;
}

void Character::attack(){
    // todo
}

void Character::die(){
    // todo
}

void Character::draw() {
    
}
