// test_ArrayStack.cpp
#include "ArrayStack.h"
#include <iostream>


int main(void) {
// Create an instance of ArrayStack named stack1 
//   using the default constructor
// Push 1.0, 2.0, 3.0, 4.0, 5.0 in this stack
 ArrayStack stack1;
  for(double i =1; i <= 5; i++){
    stack1.push(i);
  }

// Create another instance of ArrayStack named stack2
//   using the other constructor, specify an original size of 5
// Push 1.0, 2.0, ..., 10.0 in this stack
ArrayStack stack2(5);
  for(double j=1; j<= 10; j++){
    stack1.push(j);
  
  }

return 0;
}
