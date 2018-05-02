//
//  Pipe.cpp
//  SuperOOPBros
//
//  Created by Maxime Moison on 4/29/18.
//  Copyright © 2018 Maxime Moison. All rights reserved.
//

#include "Pipe.hpp"


Pipe::Pipe(float x, float y, float h) {
    
    this->x = x;
    this->y = y;
    this->h = h;
    
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    
    top_texture_id = SOIL_load_OGL_texture (
                                            "TopPipe.png",
                                            SOIL_LOAD_AUTO,
                                            SOIL_CREATE_NEW_ID,
                                            SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                                            );
    
    bottom_texture_id = SOIL_load_OGL_texture (
                                            "BottomPipe.png",
                                            SOIL_LOAD_AUTO,
                                            SOIL_CREATE_NEW_ID,
                                            SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                                            );
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    
    moving = false;
}

Pipe::~Pipe() { }

bool Pipe::collidesWith(Object* object) {
    return false;
}

void Pipe::draw() {
    
    float topMinY = y + h/2.0;
    float topMaxY = 1; /*topMinY + TOP_HEIGHT;*/ //Should be 1
    
    float bottomMaxY = y - h/2.0;
    float bottomMinY = -1; /*bottomMaxY - BOTTOM_HEIGHT*/ //Should be -1
    
    float minX = x - WIDTH/2.0;
    float maxX = x + WIDTH/2.0;
    
    
    glBindTexture( GL_TEXTURE_2D, top_texture_id );
    glEnable(GL_TEXTURE_2D);
    
    glBegin(GL_QUADS);
    glColor4f(1, 1, 1, 1);
    glTexCoord2f(0, 0);
    glVertex2f(minX, topMinY);
    
    glTexCoord2f(0, 1);
    glVertex2f(minX, topMaxY);
    
    glTexCoord2f(1, 1);
    glVertex2f(maxX, topMaxY);
    
    glTexCoord2f(1, 0);
    glVertex2f(maxX, topMinY);
    
    glEnd();
    
    glDisable(GL_TEXTURE_2D);
    
    glBindTexture( GL_TEXTURE_2D, bottom_texture_id );
    glEnable(GL_TEXTURE_2D);
    
    glBegin(GL_QUADS);
    glColor4f(1, 1, 1, 1);
    glTexCoord2f(0, 0);
    glVertex2f(minX, bottomMinY);
    
    glTexCoord2f(0, 1);
    glVertex2f(minX, bottomMaxY);
    
    glTexCoord2f(1, 1);
    glVertex2f(maxX, bottomMaxY);
    
    glTexCoord2f(1, 0);
    glVertex2f(maxX, bottomMinY);
    
    glEnd();
    
    glDisable(GL_TEXTURE_2D);
}

void Pipe::updateX(double x) {
    this->x = x;
}

void Pipe::move() {
    moving = true;
    if(moving) {
        x -= 0.005;
    }
}

void randomY() {
    
}

