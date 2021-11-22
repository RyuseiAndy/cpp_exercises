#include <queue>
#include <vector>

struct Point {
Point() : x(0.0), y(0.0), z(0.0) {}
Point(double x, double y, double z) : x(x), y(y), z(z) {}
  double x, y, z;
};

class Compare{
public:
  bool operator() (Point p1,Point p2){
    if(((p1.x * p1.x) + (p1.y * p1.y) + (p1.z * p1.z)) < ((p2.x * p2.x) + (p2.y * p2.y) + (p2.z * p2.z)))
    return true;
    else return false;
  }
};

std::vector<Point> find_k_closest(int k, std::vector<Point> p)
{
  std::vector<Point> closest;
  std::vector<Point>::iterator it = closest.begin();
  Compare cmp;
  std::priority_queue<Point, std::vector<Point>, Compare> queue(cmp);
  for(int i = 0; i < k; i++){
    queue.push(p[i]);
  }
  for(int i = k; i < p.size(); i++){
    if(cmp(p[i],queue.top())){
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