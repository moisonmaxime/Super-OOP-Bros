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
                                            "TopPipeLongx10.png",
                                            SOIL_LOAD_AUTO,
                                            SOIL_CREATE_NEW_ID,
                                            SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                                            );
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    
    bottom_texture_id = SOIL_load_OGL_texture (
                                               "BottomPipeLongx10.png",
                                               SOIL_LOAD_AUTO,
                                               SOIL_CREATE_NEW_ID,
                                               SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                                               );
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
}

Pipe::~Pipe() { }

bool Pipe::collidesWith(Object* object) {
    float minX = x - WIDTH/2.0;
    float maxX = x + WIDTH/2.0;
    float bottomMaxY = y - h/2.0;
    float topMinY = y + h/2.0;
    
    if ((minX < object->getMinX()+0.02 && object->getMinX()+0.02 < maxX)
        || (minX < object->getMaxX()-0.02  && object->getMaxX()-0.02 < maxX)) {
        if (object->getMinY()+0.02 < bottomMaxY)
            return true;
        if (object->getMaxY()-0.02 > topMinY)
            return true;
    }
    
    return false;
}

void Pipe::calculateNextFrame() {
    x -= SPEED;
    if (x < -1-WIDTH)
        x = 1+WIDTH;
}

void Pipe::draw() {
    
    float topMinY = y + h/2.0;
    float topMaxY = topMinY + HEIGHT;
    
    float bottomMaxY = y - h/2.0;
    float bottomMinY = bottomMaxY - HEIGHT;
    
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
