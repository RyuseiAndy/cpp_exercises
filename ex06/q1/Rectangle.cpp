#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle(Point2D lc, const float w, const float h)
:left_corner(lc)  , width(w) , height(h){
}

string Rectangle::get_name()const{
  return "Rectangle";
}

float Rectangle::compute_area()const{
  return width * height;
}

void Rectangle::translate(float tx, float ty){
  cout << endl;
  cout << "left_corner: x=" << left_corner.x << ", left_corner: y=" << left_corner.y << endl;

  left_corner.x += tx;
  left_corner.y += ty;

  cout << "Move to Rectangle: x= " <<left_corner.x << ", Move to Rectangle: y= " << left_corner.y << endl;
}

Rectangle::~Rectangle(){}