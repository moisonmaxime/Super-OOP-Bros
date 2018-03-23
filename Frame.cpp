//
//  Frame.cpp
//  SuperOOPBros
//
//  Created by Maxime Moison on 3/22/18.
//  Copyright © 2018 Maxime Moison. All rights reserved.
//

#include "Frame.hpp"

Frame::Frame(){
    x = 0.0f;
    y = 0.0f;
    width = 0.0f;
    height = 0.0f;
}

Frame::Frame(float x, float y, float width, float height){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Frame::draw(){
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x+width, y);
    glVertex2f(x+width, y-height);
    glVertex2f(x, y-height);
    glEnd();
}