#include "PowerUP.hpp"

bool powerupEnabled = false;

PowerUP::~PowerUP() { }

bool PowerUP::collidesWith(Object* object) {

    float minY = y - HEIGHT/2.0;
    float maxY = y + HEIGHT/2.0;
    
    float minX = x - WIDTH/2.0;
    float maxX = x + WIDTH/2.0;
    
    if ((minX < object->getMinX()+0.02 && object->getMinX()+0.02 < maxX)
        || (minX < object->getMaxX()-0.02  && object->getMaxX()-0.02 < maxX)) {
        if (object->getMinY()+0.02 < minY)
            return true;
        if (object->getMaxY()-0.02 > maxY)
            return true;
    }
    
    return false;
}

void PowerUP::calculateNextFrame(PhysicsController* pc) {

    x -= pc->getSpeed();

    if (x < -1.5) {
      x = 1.5;
      float minY = -0.95 + h/2;
      float maxY = 0.95 - h/2;
      y = minY + (rand()/(RAND_MAX/(maxY-minY)));
    }
}

void PowerUP::draw() {

    float minY = y - HEIGHT/2.0;
    float maxY = y + HEIGHT/2.0;

    float minX = x - WIDTH/2.0;
    float maxX = x + WIDTH/2.0;

    glBindTexture( GL_TEXTURE_2D, texture_id );
    glEnable(GL_TEXTURE_2D);

    glBegin(GL_QUADS);
    glColor4f(1, 1, 1, 1);
    glTexCoord2f(0, 0);
    glVertex2f(minX, minY);

    glTexCoord2f(0, 1);
    glVertex2f(minX, maxY);

    glTexCoord2f(1, 1);
    glVertex2f(maxX, maxY);

    glTexCoord2f(1, 0);
    glVertex2f(maxX, minY);
    glEnd();

    glDisable(GL_TEXTURE_2D);


}
