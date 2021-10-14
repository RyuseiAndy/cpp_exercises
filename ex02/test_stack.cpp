#include "stack.h"
#include "stack.cpp"

int main(){
    Stack sampleStack;
    sampleStack.push("ryusei");
    cout << sampleStack.top() << endl;
    sampleStack.push("Ishida");
    sampleStack.push("Andy");
    cout << sampleStack.top() << endl;
    sampleStack.pop();
    cout << sampleStack.top() << endl;
    sampleStack.pop();
    cout << (sampleStack.empty() ? "empty" : "not empty") << endl;
    return 0;
}