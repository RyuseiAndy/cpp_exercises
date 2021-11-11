#include "stack.h"

bool Stack::empty(){
  if(size() == -1){
        return true;
  } else{
        return false;
  }
}

bool Stack::full(){
  if(size() < _max_size-1){
        return false;
  } else{
        return true;
     }
}

 int Stack::size(){
     return _top;
 }

 void Stack::push(std::string n){
    if(!full()){
        _data[++_top] = n;
    } 
}

 void Stack::pop(){
    if(!empty()){
        --_top;
    } 
}

 std::string Stack::top()
 {
    return _data[_top];
 }