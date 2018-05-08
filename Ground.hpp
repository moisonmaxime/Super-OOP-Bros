//
//  Ground.hpp
//  SuperOOPBros
//
//  Created by Giovanni Gonzalez on 5/2/18.
//  Copyright © 2018 Maxime Moison. All rights reserved.
//

#ifndef Ground_hpp
#define Ground_hpp

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

class Ground {
    float progress;
    float tex2;
    float tex3;
    GLuint texture_id;
public:
    Ground(const char*);
    void draw();
    void incProgress(float speed);
};

#endif /* Ground_hpp */
