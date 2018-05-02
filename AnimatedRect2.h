//
//  AnimatedRect2.h
//  SuperOOPBros
//
//  Created by Giovanni Gonzalez on 5/2/18.
//  Copyright © 2018 Maxime Moison. All rights reserved.
//

#ifndef AnimatedRect2_h
#define AnimatedRect2_h


#if defined WIN32
#include <freeglut.h>
#include "../windows/SOIL.h"
#elif defined __APPLE__
#include <GLUT/glut.h>
#include <SOIL.h>
#else
#include <GL/freeglut.h>
#include <SOIL.h>
#endif

class AnimatedRect2 {
    float x;
    float y;
    float w;
    float h;
    GLuint texture_map_id;
    
    int rows;
    int cols;
    
    int curr_row;
    int curr_col;
    
    bool complete;
    bool animating;
public:
    AnimatedRect2 (const char*, int, int, float, float, float, float);
    
    bool done();
    
    void draw();
    
    void advance();
    
    void incY();
    
    void reset();
    
    void animate();
    
    void stop();
};

#endif /* AnimatedRect2_h */
