#ifndef TexRect_h
#define TexRect_h

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include "RgbImage.h"

class TexRect {
    float* x;
    float* y;
    float* w;
    float* h;

    GLuint texture_id;
    GLuint texture_id1;
    GLuint texture_id2;

    int animatedRows;
    int animatedCols;
    
    int curr_row;
    int curr_col;
    
    bool exploding1;
    bool complete;
public:
    TexRect(const char*, const char*, int, int, float*, float*, float*, float*);
    
    bool done();
    
    void draw();
    
    void advance();
    
    void incY();
    
    void reset();
    
    bool contains(float x, float y);
    
    void explode(TexRect* sprite);
    
    bool exploding();
};

#endif
