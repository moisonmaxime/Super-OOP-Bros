//
//  Frame.cpp
//  SuperOOPBros
//
//  Created by Maxime Moison on 3/22/18.
//  Copyright © 2018 Maxime Moison. All rights reserved.
//

#include "Frame.hpp"

Frame::Frame(){
    x = 0;
    y = 0;
    width = 0.5;
    height = 0.5;
}

Frame::Frame(float x, float y, float width, float height){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

bool Frame::contains(float x, float y) {
    return (this->x <= x && x <= this->x + this->width) && (this->y <= y && y <= this->y + this->height);
}

bool Frame::collidesWith(Frame f) {
    float xCorners[] = {this->x, this->x + this->width};
    float yCorners[] = {this->y, this->y + this->height};
    float xCornersOther[] = {f.x, f.x + f.width};
    float yCornersOther[] = {f.y, f.y + f.height};
    
    for (int i=0; i<2; i++) {
        if (f.contains(xCorners[i], yCorners[i]))
            return true;
        if (f.contains(xCorners[(i+1) %2], yCorners[i]))
            return true;
        if (this->contains(xCornersOther[i], yCornersOther[i]))
            return true;
        if (this->contains(xCornersOther[(i+1) %2], yCornersOther[i]))
            return true;
    }
    return false;
}

void Frame::draw(){
    glColor3f(.1, .1, .1);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x+width, y);
    glVertex2f(x+width, y+height);
    glVertex2f(x, y+height);
    glEnd();
}
