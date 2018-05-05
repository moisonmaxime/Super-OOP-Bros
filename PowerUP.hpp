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

#define SPEED 0.005

class PowerUP {
    GLuint slow_texture_id;
    float x, y, h;
public:
    PowerUP(float x, float y, float h);
    ~PowerUP();
    void calculateNextFrame();
    bool collidesWith(Object* object);
    void draw();
};

#endif /* PowerUP_hpp */
