//
//  Box.hpp
//  SuperOOPBros
//
//  Created by Maxime Moison on 3/24/18.
//  Copyright © 2018 Maxime Moison. All rights reserved.
//

#ifndef Box_hpp
#define Box_hpp

#include "Object.hpp"

class Box: public Object {
    Frame hitbox;
public:
    Box();
    Box(float x, float y, float width, float height);
    float getX();
    float getY();
    Frame getHitbox();
    void setPosition(float x, float y);
    Side collidesWith(Object* other);
    void draw();
};

#endif /* Box_hpp */
