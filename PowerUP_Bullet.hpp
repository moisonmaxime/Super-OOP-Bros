#ifndef PowerUP_Bullet_HPP
#define PowerUP_Bullet_HPP

#include "PowerUP.hpp"

class PowerUP_Bullet: public PowerUP{
public: 
    PowerUP_Bullet(const char* filename, int rows, int cols, float x, float y, float h, PhysicsController* pc, Character* player);
    void reset();
    void apply();
};

#endif
