#include "PowerUP.hpp"

bool powerupEnabled = false;

PowerUP::~PowerUP() { }

bool PowerUP::collidesWith(Object* object) {
    if(player->getState()){
        return false;
    }
    return this->hitbox.collidesWith(object->getHitbox());
}

void PowerUP::calculateNextFrame() {
    hitbox.x -= pc->getSpeed();
    if(hitbox.x < -1.5) {
        hitbox.x = 1.5;
        float minY = -0.95 + hitbox.height/2;
        float maxY = 0.95 - hitbox.height/2;
        hitbox.y = minY + (rand()/(RAND_MAX/(maxY-minY)));
    }
}

void PowerUP::draw() {

    float minY = hitbox.y;
    float maxY = hitbox.y + hitbox.height;

    float minX = hitbox.x;
    float maxX = hitbox.x + hitbox.width;

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

void PowerUP::drawStatus(int i){
    float minY = .85;
    float maxY = .95;

    float minX = .9 - i*.05;
    float maxX = .95 - i*.05;

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


void PowerUP::setX(float value) {
    hitbox.x = value;
    float minY = -0.95 + hitbox.height/2;
    float maxY = 0.95 - hitbox.height/2;
    hitbox.y = minY + (rand()/(RAND_MAX/(maxY-minY)));
    this->powerupEnabled = false;
}

bool PowerUP::enabled(){
    return powerupEnabled;
}



