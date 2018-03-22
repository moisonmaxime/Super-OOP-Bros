//
//  Frame.hpp
//  SuperOOPBros
//
//  Created by Maxime Moison on 3/22/18.
//  Copyright © 2018 Maxime Moison. All rights reserved.
//

#ifndef Frame_hpp
#define Frame_hpp

class Frame {
    float x, y, width, height;
public:
    Frame();
    Frame(float x, float y, float width, float height);
    
    float getX() { return x; }
    float getY() { return y; }
    float getHeight() { return height; }
    float getWidth() { return width; }
    
    void getX(float x) { this->x = x; }
    void getY(float y) { this->y = y; }
    void getHeight(float height) { this->height = height; }
    void getWidth(float width) { this->width = width; }
    
    bool collidesWith(Frame f);
};

#endif /* Frame_hpp */
