//
//  PowerUP_Slow.cpp
//  SuperOOPBros
//
//  Created by Maxime Moison on 5/7/18.
//  Copyright © 2018 Maxime Moison. All rights reserved.
//

#include "PowerUP_Roids.hpp"

static PowerUP_Roids* power;

static void timedPowerReset(int i) {
    //todo draw powerup on corner of screen
    power->reset();
}

static void waitToMakeMortal(int i){
    power->makeMortal();
}

PowerUP_Roids::PowerUP_Roids(const char* filename, int rows, int cols, float x, float y, float h, PhysicsController* pc, Character* player) {
    
    power = this;
    this->hitbox = Frame(x, y, WIDTH_POWERUP, HEIGHT_POWERUP);
    this->pc = pc;
    this->player = player;
    powerupEnabled = false;
    
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

void PowerUP_Roids::reset(){
    powerupEnabled = false;
    power->player->setJumpForce(DEFAULT_JUMP);
    power->pc->setGravity(DEFAULT_GRAVITY);
    power->pc->setSpeed(DEFAULT_SPEED);
    glutTimerFunc(.3, waitToMakeMortal, 0);
}

void PowerUP_Roids::makeMortal(){
    power->player->setState(MORTAL);
}

void PowerUP_Roids::apply(){
    powerupEnabled = true;
    power->pc->setGravity(LOW_GRAVITY);
    power->player->setJumpForce(TINY_JUMP);
    power->player->setState(INVINCIBLE);
    power->pc->setSpeed(EXTREME_SPEED);
    glutTimerFunc(POWERUP_TIME*.5, timedPowerReset, 0);
}
 
