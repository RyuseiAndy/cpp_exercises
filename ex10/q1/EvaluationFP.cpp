#include <iostream>
#include <cstdlib>
#include <stack>
#include <string>
#include <sstream>

double EvaluationFP(std::string str){
  std::stack<double> s1;
  double a,b;
  std::stringstream x(str);
  std::string str1;
  while(getline(x,str,' ')){
    if((str1[0] == '+' || str1[0] == '-' || str1[0] == '*' || str1[0] == '/') && str1.length() <= 1){
      a = s1.top();
      s1.pop();
      b = s1.top();
      s1.pop();

      if(str1[0] == '+') s1.push(b+a);
      if(str1[0] == '-') s1.push(b-a);
      if(str1[0] == '*') s1.push(b*a);
      if(str1[0] == '/') s1.push(b/a);
    }
    else s1.push(atoi(str1.c_str()));
  }
  return  s1.top();
}

int main(){
  std::cout << "input:( 1 + ( ( 2 + 3 ) * ( 4 * 5 ) ) )" << std::endl;
  std::string str1 = "( 1 + ( ( 2 + 3 ) * ( 4 * 5 ) ) )";

  std::cout << "Output:"<<EvaluationFP(str1) << std::endl;
  return 0;
}
