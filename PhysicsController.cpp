//
//  PhysicsController.cpp
//  SuperOOPBros
//
//  Created by Maxime Moison on 3/23/18.
//  Copyright © 2018 Maxime Moison. All rights reserved.
//

#include "PhysicsController.hpp"
#include <iostream>

PhysicsController::PhysicsController() {
    this->gravity = DEFAULT_GRAVITY;
    this->gameSpeed = DEFAULT_SPEED;
}

PhysicsController::PhysicsController(float gravity, float gameSpeed) {
    this->gravity = gravity;
    this->gameSpeed = gameSpeed;
}


void PhysicsController::applyforces(MovingObject* obj) {
    this->applyGravity(obj);
}

void PhysicsController::applyGravity(MovingObject* obj) {
    if (obj->getVY() >= -0.2) {
        obj->setVY(obj->getVY() + gravity);
    }
}

void PhysicsController::setSpeed(float gameSpeed=DEFAULT_SPEED){
    this->gameSpeed = gameSpeed;
}

float PhysicsController::getSpeed(){
    return this->gameSpeed;
}