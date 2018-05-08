#include "Background.hpp"

Background::Background (const char* filename){
    
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
    
    glTexParameteri(GL_TEXTURE_2D,GL_NEAREST, GL_NEAREST);
    
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    
    //Default values
    progress = -1;
    tex2 = -1+WIDTH_BACKGROUND;
}

void Background::draw(){
    
    glBindTexture( GL_TEXTURE_2D, texture_id );
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    
    float top = 1;
    float bottom = 0;
    
    float left = 0;
    float right = 1;
    
    
    glBegin(GL_QUADS);
    
    glTexCoord2f(left, bottom);
    glVertex2f(progress, -1);
    
    glTexCoord2f(left, top);
    glVertex2f(progress, -1+HEIGHT_BACKGROUND);
    
    glTexCoord2f(right, top);
    glVertex2f(progress+WIDTH_BACKGROUND, -1+HEIGHT_BACKGROUND);
    
    glTexCoord2f(right, bottom);
    glVertex2f(progress+WIDTH_BACKGROUND, -1);
    
    glEnd();
    
    //2nd tile
    glBegin(GL_QUADS);
    
    glTexCoord2f(left, bottom);
    glVertex2f(tex2, -1);
    
    glTexCoord2f(left, top);
    glVertex2f(tex2, -1+HEIGHT_BACKGROUND);
    
    glTexCoord2f(right, top);
    glVertex2f(tex2+WIDTH_BACKGROUND, -1+HEIGHT_BACKGROUND);
    
    glTexCoord2f(right, bottom);
    glVertex2f(tex2+WIDTH_BACKGROUND, -1);
    
    glEnd();
    
    
    glDisable(GL_TEXTURE_2D);
}

void Background::incProgress(float speed){
    if (progress<=-1-WIDTH_BACKGROUND){
        progress = tex2+WIDTH_BACKGROUND-.01;
    }
    if (tex2<=-1-WIDTH_BACKGROUND){
        tex2 = progress+WIDTH_BACKGROUND-.01;
    }
    progress -= speed/4.0;
    tex2 -= speed/4.0;
}
