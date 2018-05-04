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
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include "RgbImage.hpp"

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
