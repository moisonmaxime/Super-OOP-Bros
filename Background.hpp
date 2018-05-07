#ifndef Background_hpp
#define Background_hpp

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

#define DXOVERY 9.0/16.0
#define SCALE 2.0/256.0

#define HEIGHT 256.0 * SCALE
#define WIDTH 216.0 * SCALE * DXOVERY

class Background {
    float progress;
    float tex2;
    float tex3;

    GLuint texture_id;
    
public:
    Background(const char*);
    
    void draw();
    
    void incProgress(float speed);
    
};

#endif
