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
}

PhysicsController::PhysicsController(float gravity) {
    this->gravity = gravity;
}


void PhysicsController::applyforces(MovingObject* obj) {
    this->applyGravity(obj);
}

void PhysicsController::applyGravity(MovingObject* obj) {
    if (obj->getVY() >= -0.2) {
        obj->setVY(obj->getVY() + gravity);
    }
}
