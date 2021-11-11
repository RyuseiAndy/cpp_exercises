// test_inc.cpp
#include <cassert>
// COMPLETE Include any additional necessary headers here
#include "inc.cpp"

int main(void) {
  double a = 1.0;
  //std::cout<<a<<std::endl;
  inc(a); 
  //std::cout<<a<<std::endl;
  assert(a == 2.0);
  inc(a); 
  assert(a == 3.0);

  a = 1.0;
  //std::cout<<a<<std::endl;
  inc(&a); 
  //std::cout<<a<<std::endl;
  assert(a == 2.0);
  inc(&a); 
  assert(a == 3.0);

  return 0;
}