#include "stack.cpp"
#include <fstream>
#include <string>
#include <iomanip>
#include <iostream>


void printline(int);
int i;

int main(int argc, char* argv[]){
    std::ifstream ifs( argv[1] );
    std::string str;
    Stack s;
    int line=0;

    if (!ifs)
	{
		cout << "Error! File can not be opened" << endl;
		return 0;
	}
    cout << "Contents of the data.txt file\n" << endl;

	while (getline(ifs, str))
	{
        cout << str << endl;
        if(str.length()>0){
            line=str.length();
        }
            s.push(str);
    }
    setw(line);

    cout << "\nStacked data of the data.txt file\n" << endl;

    for ( i = 0 ; i < line ;i++){
            cout << "-";
        }
        std::cout<<std::endl;

    while (!s.empty())
    {
        std::cout << s.top() << std::endl;
        s.pop();
    }
    for ( i = 0 ; i < line ;i++){
            cout << "-";
        }
        std::cout<<std::endl;

    
  return 0;
}
