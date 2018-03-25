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
#include <math.h>
#include <limits>

enum Corner { TopLeft, TopRight, BottomRight, BottomLeft, NoCorner };
enum Side { TopSide, BottomSide, RightSide, LeftSide, NoSide };

class Frame {
public:
    float x, y, width, height;
    Frame();
    Frame(float x, float y, float width, float height);
    float getMinX() { return x; }
    float getMinY() { return y; }
    float getMaxX() { return (x + width); }
    float getMaxY() { return (y + height); }
    void draw();
    
    Side collidesWith(Frame f);
    bool contains(float x, float y);
};

#endif /* Frame_hpp */
