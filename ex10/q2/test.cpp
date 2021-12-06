#include <iostream>
#include <cstring>
#include <stack>
#include <sstream>
#include <vector>
#include <iomanip>
#include <map>

using namespace std;

double twostack(const string str){
    double x, y, z;
    char flag;
    stringstream sstr(str);
    stack<double> num;
    stack<char> ope;
    string st;

    map<char, int> judg; 
    judg['+'] = 1;
    judg['-'] = 1;
    judg['*'] = 2;
    judg['/'] = 2;
    judg['('] = 0;
    judg[')'] = 0;

    ope.push('\0');

    while(sstr >> st){

        if(st == "+" || st == "-" || st == "*" || st == "/"){
            flag = *st.c_str();
            ope.push(flag);

            continue;
        }
        else if(st == "("){
            continue;
           
        }
        else if(st == ")"){
            if(ope.top() == '+'){
                ope.pop();
               
                y = num.top();
                num.pop();
                x = num.top();
                num.pop();
                num.push(x + y);
            }
            else if(ope.top() == '-'){
                ope.pop();
                
                y = num.top();
                num.pop();
                x = num.top();
                num.pop();
                num.push(x - y);
            }
            else if(ope.top() == '*'){
                ope.pop();
               
                y = num.top();
                num.pop();
                x = num.top();
                num.pop();
                num.push(x * y);
            }
            else if(ope.top() == '/'){
                ope.pop();
                
                y = num.top();
                num.pop();
                x = num.top();
                num.pop();
                num.push(x / y);
            }
            continue;

        }
        else{
            num.push(stod(st));
            continue;
        }
    }



    while(ope.top() != '\0'){
        if(judg[ope.top()] == 2){
            if(ope.top() == '*'){
                ope.pop();
               
                y = num.top();
                num.pop();
                x = num.top();
                num.pop();
                num.push(x * y);
            }
            else if(ope.top() == '/'){
                ope.pop();
                
                y = num.top();
                num.pop();
                x = num.top();
                num.pop();
                num.push(x / y);
            }
            
        }
        else if(judg[ope.top()] == 1){
            flag = ope.top();
            ope.pop();
            if(judg[ope.top()] == 1 || ope.top() == '\0'){
                if(flag == '+'){
                    y = num.top();
                    num.pop();
                    x = num.top();
                    num.pop();
                    num.push(x + y);
                }
                else if(flag == '-'){
                    y = num.top();
                    num.pop();
                    x = num.top();
                    num.pop();
                    num.push(x - y);
                }
            }
            else if(judg[ope.top()] == 2){
                z = num.top();
                num.pop();
                if(ope.top() == '*'){
                    ope.pop();
                    ope.push(flag);
                    y = num.top();
                    num.pop();
                    x = num.top();
                    num.pop();
                    num.push(x * y);
                    num.push(z);
                    continue;
                }
                else if(ope.top() == '/'){
                    ope.pop();
                    ope.push(flag);
                    y = num.top();
                    num.pop();
                    x = num.top();
                    num.pop();
                    num.push(x / y);
                    num.push(z);
                    continue;
                }

            }
            continue;
        }

    }

    return num.top();
}

int main(){
    string str1 = "3 + 5 * 6 - 7 * ( 8 + 5 )";
    string str2 = "25.0 * 12.0 / 5.0 - 8.0";
    
    cout <<  fixed << setprecision(1);

    cout << "Input: " << str1 << endl;
    cout << "Output: "<< twostack(str1) << endl;

    cout << "Input: " << str2 << endl;
    cout << "Output: "<< twostack(str2) << endl;

    return 0;

}