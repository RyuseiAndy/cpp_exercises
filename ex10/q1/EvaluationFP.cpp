#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <iomanip>
#include <map>

using namespace std;

double evaluate(string data) {
    stack<double> operand;
    stack<string> opetating;
    stringstream ss(data);
    string x;

    while(ss >> x) {
        if(x == "+" || x == "-" || x == "*" || x == "/"){
            opetating.push(x);
        }
        else if(x == "(" ) {
        }
        else if(x == ")" ) {
            double y1 = operand.top();
            operand.pop();
            double y2 = operand.top();
            operand.pop();
            string y3 = opetating.top();
            if(y3 == "+") {
                opetating.pop();
                double add = y2 + y1;
                operand.push(add);
            } else if(y3 == "-") {
                opetating.pop();
                double sum = y2 - y1;
                operand.push(sum);
            } else if(y3 == "*") {
                opetating.pop();
                double mat = y2 * y1;
                operand.push(mat);
            } else if(y3 == "/") {
                opetating.pop();
                double div = y1 / y2;
                operand.push(div);
            }
        }
        else operand.push(stod(x));
    }
    return operand.top();
}

int main() {
    string data1 = "3 + 5 * 6 - 7 * ( 8 + 5 )";
    string data2  = "25.0 * 12.0 / 5.0 - 8.0";
    string data3 = "1 + 2 * 3 - 4 * ( 5 + 6 )";

    cout << "Input: " << data1 << endl;
    cout << "output: " << evaluate(data1) << endl;
    cout << "Input: " << data2 << endl;
    cout << "output: " << evaluate(data2) << endl;
    cout << "Input: " << data3 << endl;
    cout << "output: " << evaluate(data3) << endl;
}