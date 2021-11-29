#include <iostream>
#include <string>
#include <algorithm>

#include "palindrome.h"
using namespace std;

int main() {
    string s1 = "Don't nod";
    string s2 = "Was it a cat I saw";
    string s3 = "ABCDEFG";
    cout << "s1 :" << s1 << endl;
    cout << "s2 :" << s2 << endl;
    cout << "s3 :" << s3 << endl;
    isPalindrome(s1) ?
        cout << "s1 is a palindrome" << endl :
        cout << "s1 is not a palindrome" << endl;

    isPalindrome(s2) ?
        cout << "s2 is a palindrome" << endl :
        cout << "s2 is not a palindrome" << endl;

    isPalindrome(s3) ?
        cout << "s3 is a palindrome" << endl :
        cout << "s3 is not a palindrome" << endl;

    return 0;
}