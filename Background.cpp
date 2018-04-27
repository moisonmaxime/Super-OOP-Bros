#include "Background.hpp"

Background::Background (const char* filename){
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    
    //Static image
    RgbImage theTexMap( filename );
    
    glGenTextures( 1, &texture_id );
    glBindTexture( GL_TEXTURE_2D, texture_id );
    
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, theTexMap.GetNumCols(), theTexMap.GetNumRows(),
                      GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData() );
    this->texture_id = texture_id;
    
    //Default values
    this->progress = -1.0f;
    this->tex2 = 0.0f;
    this->tex3 = 1.0f;
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