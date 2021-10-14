#include "stack.h"

bool Stack::empty()
{
    return (_top == -1);
}
bool Stack::full()
{
    return (_top == _max_size);
}

 // return the number of elements
 int Stack::size()
 {
     return _top;
 }

 // insert element on top
 // print an error message on std::cerr when overflow
 void Stack::push(std::string str)
 {
     if(full()){
         cout << "error: stack is full." << endl;
         return;
     }
     _top++;
     _data[_top]= str;
 }

 // remove element on top
 // print an error message on std::cerr when underflow
 void Stack::pop()
 {
     if(empty()){
         cout << "error: stack is empty." << endl;
        return ;
     }
        --_top;
    //_data[_top];
 }

 // acces the topmost element
 std::string Stack::top()
 {
    return _data[_top];
 }