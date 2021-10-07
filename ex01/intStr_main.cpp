#include "intStr.h"

int main(void)
{
    //printf("%s\n",intToStr(30));
    //printf("%d\n",strToInt("123"));
    char *testIntVal = intToStr(123);
    char *testStrVal = "123";
    int r = strToInt(testStrVal);
    free(testIntVal);
}