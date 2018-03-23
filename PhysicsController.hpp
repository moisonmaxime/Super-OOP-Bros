//
//  PhysicsController.hpp
//  SuperOOPBros
//
//  Created by Maxime Moison on 3/23/18.
//  Copyright © 2018 Maxime Moison. All rights reserved.
//

#ifndef PhysicsController_hpp
#define PhysicsController_hpp

#include "MovingObject.hpp"

#define DEFAULT_GRAVITY -9.8
#define DEFAULT_DRAG -1

class PhysicsController {
    float gravity;
    float drag;
    void applyGravity(MovingObject* obj);
    void applyDrag(MovingObject* obj);
public:
    PhysicsController();
    PhysicsController(float drag, float gravity);
    void applyforces(MovingObject* obj);
};

#endif /* PhysicsController_hpp */
