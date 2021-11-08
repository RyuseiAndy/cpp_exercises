// exception.cpp
#include <stdexcept>
#include <cstdio>
#include <iostream>

using namespace std;

class LogFile{
    FILE* logfile;

    void fputs(const char *s,FILE *logfile){}

};

void doSomeComputation() {   
 throw runtime_error("failure during doing some computation");
}

void example() {
 FILE* logfile = fopen("logfile.txt", "w+");
 if (!logfile) {
   throw runtime_error("failed to open file");
 }

 fputs("log - 1", logfile);

 // Call a function that performs some computation and may throw 
 // an exception

try{
    doSomeComputation();
    }catch(runtime_error& e){
        cout << e.what() << endl;
    }

 fputs("log - 2", logfile);
    
 cout << "closing logfile" << endl;
 fclose(logfile);
}

int main(void) {
 cout << "Calling example()" << endl;
 example();
 cout << "After calling example()" << endl;
 return 0;
}
