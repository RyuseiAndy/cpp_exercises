// test_inc.cpp
#include <cassert>
// COMPLETE Include any additional necessary headers here
#include "inc.h"
#include "inc.cpp"

int main(void) {
  double a = 1.0;
  inc(a); 
  assert(a == 2.0);
  inc(a); 
  assert(a == 3.0);
  //std::cout<<a<<std::endl;

  a = 1.0;
  inc(&a); 
  assert(a == 2.0);
  inc(&a); 
  assert(a == 3.0);

  return 0;
}