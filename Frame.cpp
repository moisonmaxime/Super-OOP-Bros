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

Side Frame::collidesWith(Frame f) {
    Side side = Side::NoSide;
    float dist = std::numeric_limits<float>::max();
    
    if (f.getMinX() >= this->getMinX() && f.getMinX() <= this->getMaxX()) {
        if (f.getMinY() >= this->getMinY() && f.getMinY() <= this->getMaxY()) {
            // bottomLeft = true;
            float distX = abs(f.getMinX() - this->getMaxX());
            float distY = 0.2 * abs(f.getMinY() - this->getMaxY());
            if (distX < distY) {
                if (distX < dist) {
                    side = RightSide;
                    dist = distX;
                }
            } else {
                if (distY < dist) {
                    side = TopSide;
                    dist = distY;
                }
            }
        }
        if (f.getMaxY() >= this->getMinY() && f.getMaxY() <= this->getMaxY()) {
            // topLeft = true;
            float distX = abs(f.getMinX() - this->getMaxX());
            float distY = 0.2 * abs(f.getMaxY() - this->getMinY());
            if (distX < distY) {
                if (distX < dist) {
                    side = RightSide;
                    dist = distX;
                }
            } else {
                if (distY < dist) {
                    side = BottomSide;
                    dist = distY;
                }
            }
        }
    }
    
    if (f.getMaxX() >= this->getMinX() && f.getMaxX() <= this->getMaxX()) {
        if (f.getMinY() >= this->getMinY() && f.getMinY() <= this->getMaxY()) {
            // bottomRight = true;
            float distX = abs(f.getMaxX() - this->getMinX());
            float distY = 0.2 * abs(f.getMinY() - this->getMaxY());
            if (distX < distY) {
                if (distX < dist) {
                    side = LeftSide;
                    dist = distX;
                }
            } else {
                if (distY < dist) {
                    side = TopSide;
                    dist = distY;
                }
            }
        }
        if (f.getMaxY() >= this->getMinY() && f.getMaxY() <= this->getMaxY()) {
            // topRight = true;
            float distX = abs(f.getMaxX() - this->getMinX());
            float distY = 0.2 * abs(f.getMaxY() - this->getMinY());
            if (distX < distY) {
                if (distX < dist) {
                    side = LeftSide;
                    dist = distX;
                }
            } else {
                if (distY < dist) {
                    side = BottomSide;
                    dist = distY;
                }
            }
        }
    }
    return side;
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
