#ifndef PowerUP_hpp
#define PowerUP_hpp

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
#include "PhysicsController.hpp"
#include "Character.hpp"

#define YOVERDX 16.0/9.0
#define SCALE 1.0/260.0

#define HEIGHT 242.0 * SCALE * YOVERDX
#define WIDTH 26.0 * SCALE

class PowerUP {
protected:
    GLuint texture_id;
    float x, y, h;
    bool powerupEnabled;
public:    
    void draw();
    ~PowerUP();
    bool collidesWith(Object* object);
    virtual void calculateNextFrame() = 0;
};

#endif /* PowerUP_hpp */
