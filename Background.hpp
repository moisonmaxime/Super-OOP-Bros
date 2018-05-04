#ifndef Background_hpp
#define Background_hpp

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include "RgbImage.hpp"

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
