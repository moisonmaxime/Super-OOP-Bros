//
//  Pipe.hpp
//  SuperOOPBros
//
//  Created by Maxime Moison on 4/29/18.
//  Copyright © 2018 Maxime Moison. All rights reserved.
//

#ifndef Pipe_hpp
#define Pipe_hpp

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

#include "Frame.hpp"
#include "Object.hpp"

#define TOP_HEIGHT 1
#define BOTTOM_HEIGHT 1
#define WIDTH 0.2

class Pipe {
    GLuint top_texture_id, bottom_texture_id;
    float x, y, h;
public:
    Pipe(float x, float y, float h);
    ~Pipe();
    bool collidesWith(Object* object);
    void draw();
};

#endif /* Pipe_hpp */
