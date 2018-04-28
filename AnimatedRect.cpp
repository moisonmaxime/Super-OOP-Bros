#include "AnimatedRect.h"
#include<iostream>

AnimatedRect::AnimatedRect (const char* filename, int rows, int cols, float *x, float *y, float *w, float *h){

    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    
    texture_map_id = SOIL_load_OGL_texture
    (
     filename,
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
    
    complete = false;
    animating = true;
}

bool AnimatedRect::done() {
    return complete;
}


void AnimatedRect::draw(){
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
        glColor4f(1, 1, 1, 1);
        glTexCoord2f(left, bottom);
        glVertex2f(*x, *y);

        glTexCoord2f(left, top);
        glVertex2f(*x, *y + *h);

        glTexCoord2f(right, top);
        glVertex2f(*x+*w, *y + *h);

        glTexCoord2f(right, bottom);
        glVertex2f(*x+*w, *y);

        glEnd();

        glDisable(GL_TEXTURE_2D);
    }
}

void AnimatedRect::incY(){
    *y+=0.01;
}

void AnimatedRect::advance(){
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

void AnimatedRect::reset(){
    complete = false;
}

void AnimatedRect::animate(){
    animating = true;
}

void AnimatedRect::stop(){
    //animating = false;
}
