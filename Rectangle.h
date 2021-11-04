#ifndef RECTANGLE_h
#define RECTANGLE_h
#include <iostream>
#include "Shape2D.h"

using namespace std;

class Rectangle : public Shape2D{
public:
  Rectangle();
  Rectangle(Point2D left_corner, const float width, const float height);
    string get_name()const;
    float compute_area()const;
    void translate(float tx, float ty);
  ~Rectangle();

private:
  Point2D left_corner;
  float width;
  float height;
};

#endif