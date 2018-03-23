#ifndef CHARACTER_H
#define CHARACTER_H

#include "Frame.hpp"
#include "MovingObject.hpp"

class Character: public MovingObject{
    float x, y;     // Location
	float vx, vy;   // Velocity
    Frame frame, hitbox;
public:
    Character();
    Character(float x, float y);
    float getX();
    float getY();
    float getVX();
    float getVY();
    void setPosition(float x, float y);
    void setVelocity(float vx, float vy);
    void setVX(float vx);
    void setVY(float vy);
    void attack();
    void die();
    void calculateNextFrame();
    void draw();
};

#endif
