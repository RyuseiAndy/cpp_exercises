#include <intStr.h>
#include <iostream>

char* intToStr(int num)
{
    int len=0;
    int intVal = num;
    while(intVal>=0.1)
    {
        len++;
        intVal /= 10;
    }
    count<<len<<endl;
    int intVal = len;
    char *ans = (char *)malloc(1*len);

    int arr[len];
    int val;
    for (int i = 0; i < len; i++)
    {
        arr[len-i-1] = num % 10;
        num /= 10;
    }
    for(int i =0; i < len; i++){
        ans[i] = '0' + arr[i];
    }

    return ans;
}

int strToInt(char　*str){
    int num = 0;
    
    while(*str != '\0'){
        num += *str - 48;
        num *= 10;
        str++;
    }
    
    num /= 10;
    
    return num;
}

