#include "TexRect.h"

TexRect::TexRect (const char* filename1, const char* filename2, int rows, int cols, float* x, float* y, float* w, float* h){
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    
    //Static image
    RgbImage theTexMap1( filename1 );
    
    glGenTextures( 1, &texture_id1 );
    glBindTexture( GL_TEXTURE_2D, texture_id1 );
    
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, int(theTexMap1.GetNumCols()), int(theTexMap1.GetNumRows()),
                      GL_RGB, GL_UNSIGNED_BYTE, theTexMap1.ImageData() );
    this->texture_id = texture_id1;
    //Animation
    RgbImage theTexMap2( filename2 );
    
    glGenTextures( 1, &texture_id2 );
    glBindTexture( GL_TEXTURE_2D, texture_id2 );
    
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, int(theTexMap2.GetNumCols()), int(theTexMap2.GetNumRows()),
                      GL_RGB, GL_UNSIGNED_BYTE, theTexMap2.ImageData() );
    //this->texture_id2 = texture_id2;
    
    //Default values
    this->animatedRows = rows;
    this->animatedCols = cols;
    
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    
    curr_row = 1;
    curr_col = 1;
    
    exploding1 = false;
    complete = true;
}

bool TexRect::done() {
    return complete;
}


void TexRect::draw(){
 
    glBindTexture( GL_TEXTURE_2D, texture_id );
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    
    float cols, rows;
    if(exploding1){
        cols = this->animatedCols;
        rows = this->animatedRows;
    }
    else{
        cols = 1;
        rows = 1;
    }
    
    float xinc = 1.0/cols;
    float yinc = 1.0/rows;
    
    
    float top = 1 - yinc * (curr_row - 1);
    float bottom = 1 - yinc * curr_row;
    
    float left = xinc * (curr_col - 1);
    float right = xinc * curr_col;
    
    
    glBegin(GL_QUADS);
    
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
    
    if(exploding1 && !complete){
        this->advance();
    }
    else if(exploding1 && complete){
        this->reset();
    }
    
}

void TexRect::incY(){
    *y+=0.01;
}

void TexRect::advance(){
    if (curr_col < animatedCols){
        curr_col++;
    }
    else {
        if (curr_row < animatedRows){
            curr_row++;
            curr_col = 1;
        }
        else{
            curr_row = 1;
            curr_col = 1;
        }
    }
    
    if (curr_row == animatedRows && curr_col == animatedCols){
        complete = true;
    }
}

void TexRect::reset(){
    complete = true;
    curr_row = 1;
    curr_col = 1;
    exploding1 = false;
    texture_id = texture_id1;

}

bool TexRect::contains(float x, float y){
    return ((*this->x <= x) && (*this->x + *w >= x)) &&
           ((*this->y >= y) && (*this->y - *h <= y));
}

void TexRect::explode(TexRect* sprite){
    exploding1 = true;
    texture_id = texture_id2;
    complete = false;        
    
}

bool TexRect::exploding(){
    return this->exploding1;
}

