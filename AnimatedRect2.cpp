//
//  AnimatedRect2.cpp
//  SuperOOPBros
//
//  Created by Giovanni Gonzalez on 5/2/18.
//  Copyright © 2018 Maxime Moison. All rights reserved.
//

#include "AnimatedRect2.h"


AnimatedRect2::AnimatedRect2 (const char* map_filename, int rows, int cols, float x=0, float y=0, float w=0.5, float h=0.5){
    
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    
    texture_map_id = SOIL_load_OGL_texture
    (
     map_filename,
     SOIL_LOAD_AUTO,
     SOIL_CREATE_NEW_ID,
     SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
     );
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    
    this->rows = rows;
    this->cols = cols;
    
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    
    curr_row = 1;
    curr_col = 1;
    
    complete = true;
    animating = true;
}

bool AnimatedRect2::done() {
    return complete;
}


void AnimatedRect2::draw(){
    if (animating){
        glBindTexture( GL_TEXTURE_2D, texture_map_id );
        glEnable(GL_TEXTURE_2D);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        
        
        float xinc = 1.0/cols;
        float yinc = 1.0/rows;
        
        
        float top = 1 - yinc * (curr_row - 1);
        float bottom = 1 - yinc * curr_row;
        
        float left = xinc * (curr_col - 1);
        float right = xinc * curr_col;
        
        
        glBegin(GL_QUADS);
        
        glTexCoord2f(left, bottom);
        glVertex2f(x, y - h);
        
        glTexCoord2f(left, top);
        glVertex2f(x, y);
        
        glTexCoord2f(right, top);
        glVertex2f(x+w, y);
        
        glTexCoord2f(right, bottom);
        glVertex2f(x+w, y - h);
        
        glEnd();
        
        glDisable(GL_TEXTURE_2D);
    }
}

void AnimatedRect2::incY(){
    x-= 0.005;
}

void AnimatedRect2::advance(){
    if (curr_col < cols){
        curr_col++;
    }
    else {
        if (curr_row < rows){
            curr_row++;
            curr_col = 1;
        }
        else{
            curr_row = 1;
            curr_col = 1;
        }
    }
    
    if (curr_row == rows && curr_col == cols){
        complete = true;
    }
}

void AnimatedRect2::reset(){
    complete = false;
}

void AnimatedRect2::animate(){
    animating = true;
}

void AnimatedRect2::stop(){
    //animating = false;
}
