#include "PowerUP.hpp"

bool powerupEnabled = false;

PowerUP::~PowerUP() { }

bool PowerUP::collidesWith(Object* object) {

    float minX = x - WIDTH/2.0;
    float maxX = x + WIDTH/2.0;
    float bottomMaxY = y - h/2.0;
    float topMinY = y + h/2.0;

    if ((minX < object->getMinX()+0.02 && object->getMinX()+0.02 < maxX) && (minX < object->getMaxX()-0.02  && object->getMaxX()-0.02 < maxX)) {
        if (object->getMinY()+0.02 < topMinY)
            return true;
        if (object->getMaxY()-0.02 > bottomMaxY)
            return true;
    }
    return false;
}

void PowerUP::draw() {

    float topMinY = y + h/2.0;
    float topMaxY = topMinY + HEIGHT;

    float bottomMaxY = y - h/2.0;
    float bottomMinY = bottomMaxY - HEIGHT;

    float minX = x - WIDTH/2.0;
    float maxX = x + WIDTH/2.0;


    glBindTexture( GL_TEXTURE_2D, texture_id );
    glEnable(GL_TEXTURE_2D);

    glBegin(GL_QUADS);
    glColor4f(1, 1, 1, 1);
    glTexCoord2f(0, 0);
    glVertex2f(minX, bottomMaxY);

    glTexCoord2f(0, 1);
    glVertex2f(minX, topMinY);

    glTexCoord2f(1, 1);
    glVertex2f(maxX, topMinY);

    glTexCoord2f(1, 0);
    glVertex2f(maxX, bottomMaxY);

    glEnd();

    glDisable(GL_TEXTURE_2D);


}
