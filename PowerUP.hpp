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

#define YOVERDX_POWERUP 9.0/16.0
#define SCALE_POWERUP 1.0/1024.0

#define HEIGHT_POWERUP 142.0 * SCALE_POWERUP
#define WIDTH_POWERUP 142.0 * SCALE_POWERUP * YOVERDX_POWERUP

class PowerUP {
protected:
    GLuint texture_id;
    Frame hitbox;
    bool powerupEnabled;
public:
    void draw();
    ~PowerUP();
    bool collidesWith(Object* object);
    void calculateNextFrame(PhysicsController* pc);
    virtual void reset(PhysicsController* pc) = 0;
    virtual void apply(PhysicsController* pc) = 0;
};

#endif /* PowerUP_hpp */
