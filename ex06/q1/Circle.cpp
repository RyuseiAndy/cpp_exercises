#include <iostream>
#include "Circle.h"

using namespace std;
extern const float Pi;

Circle::Circle(Point2D ce, float ra)
  : center(ce) , radius(ra){
}

string Circle::get_name()const{
  return "Circle";
}

float Circle::compute_area()const{
  return radius * radius * Pi;
}

void Circle::translate(float tx, float ty){
  cout << endl;
  cout << "Circle: x = " << center.x << ", Circle: y = " << center.y << endl;

  center.x += tx;
  center.y += ty;

  cout << "Move to Circle: x = "<< center.x << ",Move to Circle: y = " << center.y << endl;
}

Circle::~Circle(){}