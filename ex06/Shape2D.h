#ifndef SHAPE2D_H
#define SHAPE2D_H
#include <cmath>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

inline void assertFloat(float x, float y, float eps=1e-5){
  assert(std::fabs(x-y) < eps);
}

class Point2D{
public:
  Point2D(){}
  Point2D(float x, float y)
    : x(x) , y(y){
  }
    
  float x;
  float y;
  float x_i[99];
  float y_i[99];

  Point2D *vertices;

  ~Point2D(){}
};

class Shape2D{
public:
  virtual string get_name() const = 0;
  virtual float compute_area() const = 0;
  virtual void translate(float tx, float ty) = 0;

  virtual ~Shape2D(){}
};


#endif // SHAPE2D_H