#ifndef PowerUP_Slow_HPP
#define PowerUP_Slow_HPP

#include "PowerUP.hpp"

class PowerUP_Slow: public PowerUP{
public: 
    PowerUP_Slow(const char* filename, int rows, int cols, float x, float y, float h, PhysicsController* pc);
    void reset();
    void apply();
};

#endif
