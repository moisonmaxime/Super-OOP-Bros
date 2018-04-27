//
//  Box.cpp
//  SuperOOPBros
//
//  Created by Maxime Moison on 3/24/18.
//  Copyright © 2018 Maxime Moison. All rights reserved.
//

#include "Box.hpp"


Box::Box() {
    this->hitbox = Frame(0, 0, 1, 1);
}

Box::Box(float x, float y, float width, float height) {
    this->hitbox = Frame(x, y, width, height);
}

float Box::getX() {
    return this->hitbox.x;
}

float Box::getY() {
    return this->hitbox.y;
}

float Box::getW() {
    return this->hitbox.width;
}

float Box::getH() {
    return this->hitbox.height;
}

Frame Box::getHitbox() {
    return this->hitbox;
}

void Box::setPosition(float x, float y) {
    this->hitbox.x = x;
    this->hitbox.y = y;
}

bool Box::collidesWith(Object* other) {
    return this->hitbox.collidesWith(other->getHitbox());
}

void Box::draw() {
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2f(hitbox.x, hitbox.y);
    glVertex2f(hitbox.x+hitbox.width, hitbox.y);
    glVertex2f(hitbox.x+hitbox.width, hitbox.y+hitbox.height);
    glVertex2f(hitbox.x, hitbox.y+hitbox.height);
    glEnd();
}
