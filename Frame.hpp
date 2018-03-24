//
//  Frame.hpp
//  SuperOOPBros
//
//  Created by Maxime Moison on 3/22/18.
//  Copyright © 2018 Maxime Moison. All rights reserved.
//

#ifndef Frame_hpp
#define Frame_hpp

#include "GlutApp.hpp"

class Frame {
public:
    float x, y, width, height;
    
    Frame();
    Frame(float x, float y, float width, float height);
    void draw();
    
    bool collidesWith(Frame f);
    bool contains(float x, float y);
};

#endif /* Frame_hpp */
