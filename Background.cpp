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
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    
    //Default values
    progress = -1.0f;
    tex2 = 0.0f;
    tex3 = 1.0f;
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
    glVertex2f(progress, 1);
    
    glTexCoord2f(right, top);
    glVertex2f(progress+1, 1);
    
    glTexCoord2f(right, bottom);
    glVertex2f(progress+1, -1);
    
    glEnd();
    
    //2nd tile
    glBegin(GL_QUADS);
    
    glTexCoord2f(left, bottom);
    glVertex2f(tex2, -1);
    
    glTexCoord2f(left, top);
    glVertex2f(tex2, 1);
    
    glTexCoord2f(right, top);
    glVertex2f(tex2+1, 1);
    
    glTexCoord2f(right, bottom);
    glVertex2f(tex2+1, -1);
    
    glEnd();
    
    //3rd tile
    glBegin(GL_QUADS);
    
    glTexCoord2f(left, bottom);
    glVertex2f(tex3, -1);
    
    glTexCoord2f(left, top);
    glVertex2f(tex3, 1);
    
    glTexCoord2f(right, top);
    glVertex2f(tex3+1, 1);
    
    glTexCoord2f(right, bottom);
    glVertex2f(tex3+1, -1);
    
    glEnd();
    
    
    glDisable(GL_TEXTURE_2D);
}

void Background::incProgress(float speed){
    if (progress<=-2){
        progress = tex3+1;
    }
    if (tex2<=-2){
        tex2 = progress+1;
    }
    if (tex3<=-2){
        tex3 = tex2+1;
    }
    progress -= speed/3.0;
    tex3 -= speed/3.0;
    tex2 -= speed/3.0;
}
