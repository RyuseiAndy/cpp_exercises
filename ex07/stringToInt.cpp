// stringToInt.cpp
#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>

using namespace std;

int stringToInt(const string& input) {
  stringstream instream;
  instream << input;
  int number;
  instream >> number;

  if (instream.fail()) {
    // Error: the input can not be converted
    cerr << "input can not be converted to an int" << endl;
    return -1;
  }

  char left;
  instream >> left;
  if (!instream.fail()) {
    // Error: there are some characters left after the int
    cerr << "input can not be converted to an int" << endl;
    return -1;
  }

  // everything went fine: returns the int
  return number;
 }

int main(void)
{
    try
    {
        string test1 = "-1";
        std::cout << stringToInt(test1) << endl;
    }
    catch (invalid_argument const &ex)
    {
       std::cout << "#1: " << ex.what() << '\n';
    }


    try
    {
        string test2 = "cc11";
        std::cout << stringToInt(test2) << endl;
    }
    catch (invalid_argument const &ex)
    {
        std::cout << "#2: " << ex.what() << '\n';
    }


    try
    {
        string test3 = "11cc";
        std::cout << stringToInt(test3) << endl;
    }
    catch (invalid_argument const &ex)
    {
       std::cout << "#3: " << ex.what() << '\n';
    }

    return 0;
}
