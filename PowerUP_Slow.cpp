//
//  PowerUP_Slow.cpp
//  SuperOOPBros
//
//  Created by Maxime Moison on 5/7/18.
//  Copyright © 2018 Maxime Moison. All rights reserved.
//

#include "PowerUP_Slow.hpp"

static PowerUP_Slow* power;

static void timedPowerReset(int i) {
    power->reset();
}

PowerUP_Slow::PowerUP_Slow(const char* filename, int rows, int cols, float x, float y, float h, PhysicsController* pc) {
    
    power = this;
    this->hitbox = Frame(x, y, WIDTH, HEIGHT);
    this->pc = pc;
    
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    
    texture_id = SOIL_load_OGL_texture (
                                        filename,
                                        SOIL_LOAD_AUTO,
                                        SOIL_CREATE_NEW_ID,
                                        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                                        );
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
}

void PowerUP_Slow::reset(){
    power->pc->setSpeed(DEFAULT_SPEED);
}

void PowerUP_Slow::apply(){
    power->pc->setSpeed(SLOW_SPEED);
    glutTimerFunc(POWERUP_TIME, timedPowerReset, 0);
}
