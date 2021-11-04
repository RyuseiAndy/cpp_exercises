#ifndef CIRCLE_h
#define CIRCLE_h
#include <iostream>
#include "Shape2D.h"

using namespace std;

class Circle : public Shape2D{
public:
  Circle();
  Circle(Point2D center, float radius);
    string get_name()const;
    float compute_area()const;
    void translate(float tx, float ty);
  ~Circle();
private:
  Point2D center;
  float radius;
};

#endif 