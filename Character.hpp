#ifndef CHARACTER_H
#define CHARACTER_H

#include "Frame.hpp"
#include "MovingObject.hpp"
#include "AnimatedRect.h"

#define DEFAULT_JUMP 0.03
#define TINY_JUMP 0.02
#define INVINCIBLE true
#define MORTAL false

enum Direction { Left=-1, Right=1};

class Character: public MovingObject{
	float vx, vy;   // Velocity
    Frame frame, hitbox;
    bool dead;
    bool roids;
    float jumpForce;
    
public:
    AnimatedRect* flyingTex; 
    AnimatedRect* deadTex;
    ~Character();
    Character(const char* filename1, const char* filename2, float x, float y);
    
    float getMinX();
    float getMaxX();
    float getMinY();
    float getMaxY();
    Frame getHitbox();
    float getVX();
    float getVY();
    float getW();
    float getH();
    
    void setPosition(float x, float y);
    void setVelocity(float vx, float vy);
    void setVX(float vx);
    void setVY(float vy);
    
    bool collidesWith(Object* other);
    void handleCollisionWith(Object *other);
    
    void setJumpForce(float);
    void setState(bool);
    bool getState();
    
    void jump();
    void move(Direction direction);
    void attack();
    void die();
    void calculateNextFrame();
    void advance();
    void draw();
    void reset();
    bool isDead();
};

#endif
