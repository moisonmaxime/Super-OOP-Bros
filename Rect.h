#ifndef Rect_h
#define Rect_h

#include <string>

using namespace std;

class Rect {

  string text;
  float x;
  float y;
  float w;
  float h;

public:
  Rect() {
    x = 0;
    y = 0;
    w = 0;
    h = 0;
  }

  Rect(float xx, float yy, float ww, float hh) {
    x = xx;
    y = yy;
    w = ww;
    h = hh;
  }

  float getX() const{
    return this->x;
  }

  float getY() const{
    return this->y;
  }

  float getW() const{
    return this->w;
  }

  float getH() const{
    return this->h;
  }

  void setText(string text){
    this->text = text;
  }

  void setX(float x){
    this->x = x;
  }

  void setY(float x){
    this->y = y;
  }

  void setXY(double x, double y){
    this->x = x;
    this->y = y;
  }

  void setW(float w){
    this->w = w;
  }

  void setH(float h){
    this->h = h;
  }

  bool contains(float x, float y) {
    return ( this->x <= x && (this->x + w >= x ) &&
           ( this->y >= y && this->y - h <= y ) );
  }

};

#endif
