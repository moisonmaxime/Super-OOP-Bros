#include "Counter.hpp" 

Counter::Counter(const char* filename){
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    
    texture_id = SOIL_load_OGL_texture
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
    
    this->cols = 10;
    
    this->x = -1;
    this->y = .7;
    this->w = .03;
    this->h = .15;
    
    curr_col = 1;
    currentScore = 0;
    maxScore = 0;
}

Counter::Counter(const char* filename, int maxScore)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    
    texture_id = SOIL_load_OGL_texture
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
    
    this->cols = 10;
    
    this->x = -1;
    this->y = .7;
    this->w = .03;
    this->h = .15;
    
    curr_col = 1;
    currentScore = 0;
    this->maxScore = maxScore;
}

void Counter::incScore(){
    currentScore++;
    if (currentScore>maxScore){
        maxScore = currentScore;
    }
}

void Counter::resetCurrentScore(){
    currentScore = 0;
    curr_col = 0;
    
}

void Counter::drawCurrentScore(){
    curr_col = currentScore/100 + 1;
    
    glBindTexture( GL_TEXTURE_2D, texture_id );
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    float xinc = 1.0/cols;

    float top = 1;
    float bottom = -1;

    float left = xinc * (curr_col - 1);
    float right = xinc * curr_col;

    glBegin(GL_QUADS);
    glColor4f(1, 1, 1, 1);
    glTexCoord2f(left, bottom);
    glVertex2f(x, y);
    glTexCoord2f(left, top);
    glVertex2f(x, y + h);
    glTexCoord2f(right, top);
    glVertex2f(x+w, y + h);
    glTexCoord2f(right, bottom);
    glVertex2f(x+w, y);
    glEnd();

    glDisable(GL_TEXTURE_2D);
    
    // 10's spot
    curr_col = currentScore/10 + 1;
    
    glBindTexture( GL_TEXTURE_2D, texture_id );
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    xinc = 1.0/cols;

    left = xinc * (curr_col - 1);
    right = xinc * curr_col;

    glBegin(GL_QUADS);
    glColor4f(1, 1, 1, 1);
    glTexCoord2f(left, bottom);
    glVertex2f(x+w, y);
    glTexCoord2f(left, top);
    glVertex2f(x+w, y + h);
    glTexCoord2f(right, top);
    glVertex2f(x+w*2, y + h);
    glTexCoord2f(right, bottom);
    glVertex2f(x+w*2, y);
    glEnd();

    glDisable(GL_TEXTURE_2D);
    
    // 1's spot
    curr_col = currentScore%10 + 1;
    
    glBindTexture( GL_TEXTURE_2D, texture_id );
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    xinc = 1.0/cols;

    left = xinc * (curr_col - 1);
    right = xinc * curr_col;

    glBegin(GL_QUADS);
    glColor4f(1, 1, 1, 1);
    glTexCoord2f(left, bottom);
    glVertex2f(x+w*2, y);
    glTexCoord2f(left, top);
    glVertex2f(x+w*2, y + h);
    glTexCoord2f(right, top);
    glVertex2f(x+w*3, y + h);
    glTexCoord2f(right, bottom);
    glVertex2f(x+w*3, y);
    glEnd();

    glDisable(GL_TEXTURE_2D);

}

void Counter::drawMaxScore(){
    //100's spot
    curr_col = maxScore/100 + 1;
    
    glBindTexture( GL_TEXTURE_2D, texture_id );
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    
    float xinc = 1.0/cols;

    float top = 1;
    float bottom = -1;

    float left = xinc * (curr_col - 1);
    float right = xinc * curr_col;

    glBegin(GL_QUADS);
    glColor4f(1, 1, 1, 1);
    glTexCoord2f(left, bottom);
    glVertex2f(x, y);
    glTexCoord2f(left, top);
    glVertex2f(x, y + h*2);
    glTexCoord2f(right, top);
    glVertex2f(x+w*2, y + h*2);
    glTexCoord2f(right, bottom);
    glVertex2f(x+w*2, y);
    glEnd();

    glDisable(GL_TEXTURE_2D);
    
    // 10's spot
    curr_col = maxScore/10 + 1;
    
    glBindTexture( GL_TEXTURE_2D, texture_id );
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    xinc = 1.0/cols;

    left = xinc * (curr_col - 1);
    right = xinc * curr_col;

    glBegin(GL_QUADS);
    glColor4f(1, 1, 1, 1);
    glTexCoord2f(left, bottom);
    glVertex2f(x+w*2, y);
    glTexCoord2f(left, top);
    glVertex2f(x+w*2, y + h*2);
    glTexCoord2f(right, top);
    glVertex2f(x+w*2*2, y + h*2);
    glTexCoord2f(right, bottom);
    glVertex2f(x+w*2*2, y);
    glEnd();

    glDisable(GL_TEXTURE_2D);
    
    // 1's spot
    curr_col = maxScore%10 + 1;
    
    glBindTexture( GL_TEXTURE_2D, texture_id );
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    xinc = 1.0/cols;

    left = xinc * (curr_col - 1);
    right = xinc * curr_col;

    glBegin(GL_QUADS);
    glColor4f(1, 1, 1, 1);
    glTexCoord2f(left, bottom);
    glVertex2f(x+w*2*2, y);
    glTexCoord2f(left, top);
    glVertex2f(x+w*2*2, y + h*2);
    glTexCoord2f(right, top);
    glVertex2f(x+w*2*3, y + h*2);
    glTexCoord2f(right, bottom);
    glVertex2f(x+w*2*3, y);
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

int Counter::getMaxScore(){
    return this->maxScore;
}

void Counter::drawScores(){
    this->drawCurrentScore();
    this->drawMaxScore();    
}
