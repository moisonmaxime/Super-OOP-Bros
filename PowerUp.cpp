#include "PowerUP.hpp"

bool powerupEnabled = false;

PowerUP::PowerUP(float x, float y, float h) {

    this->x = x;
    this->y = y;
    this->h = h;

    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);

    slow_texture_id = SOIL_load_OGL_texture (
                                            "snail.png",
                                            SOIL_LOAD_AUTO,
                                            SOIL_CREATE_NEW_ID,
                                            SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                                            );

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);


}

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

void PowerUP::calculateNextFrame() {
  if(powerupEnabled) {
    x -= 0.003;
    std::cout << "POWERUP_SPEED: " << 0.003 << '\n';
  } else {
    x -= DEFAULT_SPEED;
    std::cout << "Default: " << DEFAULT_SPEED << '\n';
  }

  if (x < -1.5) {
      x = 1.5;
      float minY = -0.95 + h/2;
      float maxY = 0.95 - h/2;
      y = minY + (rand()/(RAND_MAX/(maxY-minY)));
  }
}

void PowerUP::draw() {

    float topMinY = y + h/2.0;
    float topMaxY = topMinY + HEIGHT;

    float bottomMaxY = y - h/2.0;
    float bottomMinY = bottomMaxY - HEIGHT;

    float minX = x - WIDTH/2.0;
    float maxX = x + WIDTH/2.0;


    glBindTexture( GL_TEXTURE_2D, slow_texture_id );
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
