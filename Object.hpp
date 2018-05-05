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
    virtual float getMinX() = 0;
    virtual float getMaxX() = 0;
    virtual float getMinY() = 0;
    virtual float getMaxY() = 0;
    virtual Frame getHitbox() = 0;
    virtual void setPosition(float x, float y) = 0;
    virtual bool collidesWith(Object* other) = 0;
};

#endif /* Object_h */
