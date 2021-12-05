#include "intStr.h"
#include "intStr.cpp"
#include <cstdlib> 
#include <iostream>

int main(void) {
  int num1 = 532;
  char* c1 = intToStr(num1);
  std::cout << c1 << std::endl;
  free(c1);

  char* c2 = (char*)"RYUSEI";
  int i2 = strToInt(c2);
  std::cout << i2 << std::endl;

  int num2 = 99;
  char* c3 = intToStr(num2);
  std::cout << c3 << std::endl;
  free(c3);

  char* c4 = (char*)"ISHIDA";
  int i4 = strToInt(c4);
  std::cout << i4 << std::endl;
}