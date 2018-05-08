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

#define YOVERDX 9.0/16.0
#define SCALE 1.0/1024.0

#define HEIGHT 142.0 * SCALE
#define WIDTH 142.0 * SCALE * YOVERDX

#define POWERUP_TIME 3000

class PowerUP {
protected:
    GLuint texture_id;
    Frame hitbox;
    bool powerupEnabled;
    PhysicsController* pc;
public:
    void draw();
    ~PowerUP();
    bool collidesWith(Object* object);
    void calculateNextFrame();
    virtual void reset() = 0;
    virtual void apply() = 0;
    void setX(float);
};

#endif /* PowerUP_hpp */
