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
    this->drag = DEFAULT_DRAG;
}

PhysicsController::PhysicsController(float drag, float gravity) {
    this->gravity = gravity;
    this->drag = drag;
}


void PhysicsController::applyforces(MovingObject* obj) {
    this->applyDrag(obj);
    this->applyGravity(obj);
}

void PhysicsController::applyGravity(MovingObject* obj) {
    if (obj->getVY() >= -0.2) {
        obj->setVY(obj->getVY() + gravity * 0.01);
    }
    std::cout << "Speed Y: " << obj->getVY() << std::endl;
}

void PhysicsController::applyDrag(MovingObject* obj) {
    std::cout << "Speed X: " << obj->getVX() << std::endl;
    if (obj->getVX() < 0.005 && obj->getVX() > -0.005) {
        obj->setVX(0);
        return;
    }
    float multiplier = (obj->getVX() < 0 ? -1 : 1);
    float newSpeed = obj->getVX() + multiplier * drag * 0.01;
    obj->setVX(newSpeed);
}
