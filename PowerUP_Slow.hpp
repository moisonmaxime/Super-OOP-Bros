#ifndef PowerUP_Slow_HPP
#define PowerUP_Slow_HPP

#include "PowerUP.hpp"

class PowerUP_Slow: public PowerUP{ 

public: 
    PowerUP_Slow(const char* filename, int rows, int cols, float x, float y, float h) {

        this->x = x;
        this->y = y;
        this->h = h;

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


    void calculateNextFrame() {

        x -= DEFAULT_SPEED;
    
        if (x < -1.5) {
          x = 1.5;
          float minY = -0.95 + h/2;
          float maxY = 0.95 - h/2;
          y = minY + (rand()/(RAND_MAX/(maxY-minY)));
        }
    }
    
    
};

#endif