#include "stack.cpp"
#include <fstream>
#include <string>
#include <iomanip>

void printline(int);
int i;

int main(){
    std::ifstream ifs( "data.txt" );
    std::string str;
    Stack s;
    int line=0;

    if (ifs.fail()) {
        std::cerr << "File Open Error" << std::endl;
        return -1;
    }
    while (getline(ifs, str)) {
        if(str.length() > 0){
            line = str.length();
        }
        if( str!="\n"){
            s.push(str);
        }   
    }
        setw(line);

        for ( i = 0 ; i < line+1 ;i++){
            cout << "-";
            }
        std::cout<<std::endl;

    while (!s.empty())
    {
        std::cout << s.top() << std::endl;
        s.pop();
        }
        for ( i = 0 ; i < line+1 ;i++){
            cout << "-";
            }
        std::cout<<std::endl;

  return 0;
}