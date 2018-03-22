#ifndef CHARACTER_H
#define CHARACTER_H

class Character{
	float x, y;     // Location
	float vx, vy;   // Velocity
public:
    Character();
    Character(float x, float y);
    void setPostion(int x, int y);
    void setVelocity(int vx, int vy);
    void attack();
    void die();
    void draw();
};

#endif
