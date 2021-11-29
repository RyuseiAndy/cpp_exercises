#ifndef _PALINDROME_H_
#define _PALINDROME_H_
#include <iostream>
#include <string>
#include <algorithm>

bool isPalindrome(std::string& s) {
    std::string str = s;

    transform(str.begin(), str.end(), str.begin(),
        [](unsigned char c) { return tolower(c); });

    
    str.erase(remove(str.begin(), str.end(), ' '), str.end());

    str.erase(remove(str.begin(), str.end(), ','), str.end());

    str.erase(remove(str.begin(), str.end(), '\''), str.end());
    
    
    if (equal(str.begin(), str.begin() + str.size() / 2, str.rbegin())) {
        return true;
    }
    else {
        return false;
    }

}



















#endif