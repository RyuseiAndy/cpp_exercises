// test_ArrayStack.cpp
#include "ArrayStack.h"
//#include <iostream>


int main(void) {
// Create an instance of ArrayStack named stack1 
//   using the default constructor
// Push 1.0, 2.0, 3.0, 4.0, 5.0 in this stack
  ArrayStack stack1;

    for(double i =1; i <= 5; i++){
      stack1.push(i);
    }

    /*double length = stack1.size();
        for(int i=0; i<length; i++){
            if(!stack1.empty()){
              stack1.pop();
            }
        }
    */
// Create another instance of ArrayStack named stack2
//   using the other constructor, specify an original size of 5
// Push 1.0, 2.0, ..., 10.0 in this stack
  ArrayStack stack2(5);

    for(double j=1; j<= 10; j++){
      stack1.push(j);
    }

    /*double length = stack2.size();
        for(int i=0; i<length; i++){
            if(!stack1.empty()){
                stack1.pop();
            }
        }
*/
  // Copy
    ArrayStack stack3(stack1);
    ArrayStack stack4 = stack2;

    // Assignment
    ArrayStack stack5;
    stack5 = stack1;
    ArrayStack stack6(10);
    stack6 = stack6;

    // COMPLETE 
    // Show the content of the stacks 'stack1', 'stack3' and 'stack4' by calls to pop() and top() 
    // (use a loop and the method ArrayStack::empty() for the termination condition)


    // Move
    ArrayStack stack7 = std::move(stack5);

    stack6 = std::move(stack2);

    // COMPLETE 
    // Show the content of the stacks 'stack5', 'stack7', 'stack6' and 'stack2'
    // (use the same method as in question 2)


  
return 0;
}