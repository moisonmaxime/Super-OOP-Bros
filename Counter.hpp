 
#ifndef COUNTER_HPP
#define COUNTER_HPP

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

class Counter{
    GLuint texture_id;
    
    float x;
    float y;
    float w;
    float h;
    
    int cols;
    int curr_col;
    
    int currentScore;
    int maxScore;
public:
    Counter(const char* filename);
    void incScore();
    void resetCurrentScore();
    void drawScores();
    void drawCurrentScore();
    void drawMaxScore();
};

#endif