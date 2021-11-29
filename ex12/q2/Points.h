#include <queue>
#include <vector>
#include<cmath>

struct Point {
Point() : x(0.0), y(0.0), z(0.0) {}
Point(double x, double y, double z) : x(x), y(y), z(z) {}
  double x, y, z;
};

std::vector<Point> find_k_closest2(int k, std::vector<Point> p)
{
  std::vector<Point> closest;
  std::vector<Point>::iterator it = closest.begin();
  
  auto Compare =[](Point p1,Point p2){
    if((sqrt((p1.x * p1.x) + (p1.y * p1.y) + (p1.z * p1.z))) < (sqrt((p2.x * p2.x) + (p2.y * p2.y) + (p2.z * p2.z))))
    return true;
    else return false;
  };
   
  std::priority_queue<Point, std::vector<Point>, decltype (Compare)> queue(Compare);

  for(int i = 0; i < k; i++){
      queue.push(p[i]);
    }
    for(int i = k; i < p.size(); i++){
      if(Compare(p[i],queue.top())){
        queue.pop();
        queue.push(p[i]);
      }
    }
    for(int i = 0; i < k; i++){
      closest.insert(it,queue.top());
      it = closest.begin();
      queue.pop();
    }
    return closest;
  }
