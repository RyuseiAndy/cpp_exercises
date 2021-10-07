char *intToStr(int intVal)
{
  int length = 0;
  int tmpIntVal = intVal;

  while (tmpIntVal >= 0.1)
  {
    length++;
    tmpIntVal = tmpIntVal / 10;
  }
  char *ans = (char *)malloc(1 * length);

  int arr[length];
  int val;
  for (int i = 0; i < length; i++)
  {
    arr[length - 1] = intVal % 10;
    intVal = intVal / 10;
  }
  for (int i = length - 1; i >= 0; i--)
  {
    ans[i] = '0' + arr[i];
  }
  return ans;
}

int strToInt(char　*str)
{
    int num = 0;
    int len = 0;
    
    while(*str != '\0'){
        num += *str - 48;
        num *= 10;
        str++;
    }
    
    num /= 10;
    
    return num;
}

