//
//  Object.h
//  SuperOOPBros
//
//  Created by Maxime Moison on 3/24/18.
//  Copyright © 2018 Maxime Moison. All rights reserved.
//

#ifndef Object_h
#define Object_h

#include "Frame.hpp"

class Object {
public:
    virtual float getX() = 0;
    virtual float getY() = 0;
    virtual Frame getHitbox() = 0;
    virtual void setPosition(float x, float y) = 0;
    virtual Side collidesWith(Object* other) = 0;
};

#endif /* Object_h */
