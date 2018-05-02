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
    void applyGravity(MovingObject* obj);
public:
    PhysicsController();
    PhysicsController(float gravity);
    void applyforces(MovingObject* obj);
};

#endif /* PhysicsController_hpp */
