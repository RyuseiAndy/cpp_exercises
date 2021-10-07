#include <intStr.h>
#include <iostream>
#include <memory>

intToStr::intStr(int num)
:num_(num)
{}

char* intStr::intToStr(int)
{
   int* S = (int*)malloc(sizeof(int) * num_);
    
}
int intStr::strToInt(char*)
{
    
}
