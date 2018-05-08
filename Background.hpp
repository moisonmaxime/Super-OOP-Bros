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

#define DXOVERY_BACKGROUND 9.0/16.0
#define SCALE_BACKGROUND 2.2/512.0

#define HEIGHT_BACKGROUND 512.0 * SCALE_BACKGROUND
#define WIDTH_BACKGROUND 824.0 * SCALE_BACKGROUND * DXOVERY_BACKGROUND

class Background {
    float progress;
    float tex2;

    GLuint texture_id;
    
public:
    Background(const char*);
    
    void draw();
    
    void incProgress(float speed);
    
};

#endif
