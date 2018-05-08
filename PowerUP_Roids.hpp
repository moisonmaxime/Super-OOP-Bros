#ifndef PowerUP_Roids_HPP
#define PowerUP_Roids_HPP

#include "PowerUP.hpp"

class PowerUP_Roids: public PowerUP{
public: 
    PowerUP_Roids(const char* filename, int rows, int cols, float x, float y, float h, PhysicsController* pc, Character* player);
    void makeMortal();
    void reset();
    void apply();
};

#endif
 
