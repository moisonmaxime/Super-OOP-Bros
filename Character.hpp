#ifndef CHARACTER_H
#define CHARACTER_H

#include "Frame.hpp"
#include "MovingObject.hpp"
#include "TexRect.h"

enum Direction { Left=-1, Right=1};

class Character: public MovingObject{
	float vx, vy;   // Velocity
    float jumpTime;
    Frame frame, hitbox;
    bool dead;
    
public:
    TexRect* texture; 
    Character();
    Character(float x, float y);
    
    float getX();
    float getY();
    Frame getHitbox();
    float getVX();
    float getVY();
    float getW();
    float getH();
    
    void setPosition(float x, float y);
    void setVelocity(float vx, float vy);
    void setVX(float vx);
    void setVY(float vy);
    
    Side collidesWith(Object* other);
    void handleCollisionWith(Object *other);
    
    void jump();
    void move(Direction direction);
    void attack();
    void die();
    void calculateNextFrame();
    void draw();
};

#endif
