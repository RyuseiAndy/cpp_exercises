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
            double a1 = operand.top();
            operand.pop();
            double a2 = operand.top();
            operand.pop();
            string a3 = opetating.top();
            if(a3 == "+") {
                opetating.pop();
                double b1 = a2 + a1;
                operand.push(b1);
            } else if(a3 == "-") {
                opetating.pop();
                double b2 = a2 - a1;
                operand.push(b2);
            } else if(a3 == "*") {
                opetating.pop();
                double b3 = a2 * a1;
                operand.push(b3);
            } else if(a3 == "/") {
                opetating.pop();
                double b4 = a1 / a2;
                operand.push(b4);
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