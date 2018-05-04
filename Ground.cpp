//
//  Ground.cpp
//  SuperOOPBros
//
//  Created by Giovanni Gonzalez on 5/2/18.
//  Copyright © 2018 Maxime Moison. All rights reserved.
//

#include "Ground.hpp"

Ground::Ground (const char* filename){
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    
    //Static image
    RgbImage theTexMap( filename );
    
    glGenTextures( 1, &texture_id );
    glBindTexture( GL_TEXTURE_2D, texture_id );
    
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, int(theTexMap.GetNumCols()), int(theTexMap.GetNumRows()),
                      GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData() );
    //this->texture_id = texture_id;
    
    //Default values
    this->progress = -1.0f;
    this->tex2 = 0.0f;
    this->tex3 = 1.0f;
}

void Ground::draw(){
    
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
    glVertex2f(progress, -.9);
    
    glTexCoord2f(right, top);
    glVertex2f(progress+1, -.9);
    
    glTexCoord2f(right, bottom);
    glVertex2f(progress+1, -1);
    
    glEnd();
    
    //2nd tile
    glBegin(GL_QUADS);
    
    glTexCoord2f(left, bottom);
    glVertex2f(tex2, -1);
    
    glTexCoord2f(left, top);
    glVertex2f(tex2, -.9);
    
    glTexCoord2f(right, top);
    glVertex2f(tex2+1, -.9);
    
    glTexCoord2f(right, bottom);
    glVertex2f(tex2+1, -1);
    
    glEnd();
    
    //3rd tile
    glBegin(GL_QUADS);
    
    glTexCoord2f(left, bottom);
    glVertex2f(tex3, -1);
    
    glTexCoord2f(left, top);
    glVertex2f(tex3, -.9);
    
    glTexCoord2f(right, top);
    glVertex2f(tex3+1, -.9);
    
    glTexCoord2f(right, bottom);
    glVertex2f(tex3+1, -1);
    
    glEnd();
    
    
    glDisable(GL_TEXTURE_2D);
}

void Ground::incProgress(float speed){
    if (progress<=-2){
        progress = tex3+1;
    }
    if (tex2<=-2){
        tex2 = progress+1;
    }
    if (tex3<=-2){
        tex3 = tex2+1;
    }
    progress -= speed;
    tex3 -= speed;
    tex2 -= speed;
}
