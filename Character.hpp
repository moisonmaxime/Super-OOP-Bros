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
    void setPostion(int x, int y);
    void setVelocity(int vx, int vy);
    void setVX(float vx);
    void setVY(float vy);
    void attack();
    void die();
    void draw();
};

#endif
