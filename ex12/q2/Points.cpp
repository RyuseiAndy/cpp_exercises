#include "Points.h"
#include <iostream>

using namespace std;

int main(void) {
 vector<Point> points;
 points.push_back(Point(1.0,2.0,3.0));
 points.push_back(Point(4.0,4.0,4.0));
 points.push_back(Point(0.0,2.0,1.0));
 points.push_back(Point(3.0,2.0,1.0));
 points.push_back(Point(1.0,2.0,1.0));
 points.push_back(Point(2.0,2.0,1.0));

 vector<Point> closest = find_k_closest2(3, points);
 for (size_t i = 0; i < 3; ++i) {
   cout << closest[i].x << "," << closest[i].y << ","
             << closest[i].z << endl;
 }

}