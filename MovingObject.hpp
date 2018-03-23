//
//  MovingObject.hpp
//  SuperOOPBros
//
//  Created by Maxime Moison on 3/23/18.
//  Copyright © 2018 Maxime Moison. All rights reserved.
//

#ifndef MovingObject_hpp
#define MovingObject_hpp

class MovingObject {
public:
    virtual float getX() = 0;
    virtual float getY() = 0;
    virtual float getVX() = 0;
    virtual float getVY() = 0;
    virtual void setPosition(float x, float y) = 0;
    virtual void setVelocity(float vx, float vy) = 0;
    virtual void setVX(float vx) = 0;
    virtual void setVY(float vy) = 0;
};

#endif /* MovingObject_hpp */
