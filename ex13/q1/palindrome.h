#ifndef _PALINDROME_H_
#define _PALINDROME_H_
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(string data) {
    string d = data;

    transform(d.begin(), d.end(), d.begin(),
        [](unsigned char c) { return tolower(c); });

    d.erase(remove(d.begin(), d.end(), ' '), d.end());
    d.erase(remove(d.begin(), d.end(), ','), d.end());
    d.erase(remove(d.begin(), d.end(), '\''), d.end());

    if (equal(d.begin(), d.begin() + d.size() / 2, d.rbegin())) {
        cout << data << ": palindrome" << endl;
        return true;
    }
    else {
        cout << data << ": Not palindrome" << endl;
        return false;
    }
}
#endif

