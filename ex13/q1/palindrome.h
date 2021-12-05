#ifndef _PALINDROME_H_
#define _PALINDROME_H_
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

bool isPalindrome(string s) {
    string tmp = s;
    transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
              auto fn_cond = [](char c){
                  return !isalpha(c);
              };

    tmp.erase(remove_if(tmp.begin(), tmp.end(), fn_cond), tmp.end());

    string reverse = tmp;
    reverse_copy(tmp.begin(), tmp.end(), reverse.begin());

    return tmp == reverse;
}

#endif

