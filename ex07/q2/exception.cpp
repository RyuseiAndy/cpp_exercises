#include <stdexcept>
#include <cstdio>
#include <iostream>

using namespace std;

class LogFile {
    FILE* logfile;
    public:
        LogFile(const char* filename) {
            logfile = fopen(filename, "w+");
            if (!logfile) {
                throw runtime_error("Failed to open file");
            }
        }
        ~LogFile() {
            fclose(logfile);
        }
        void fputs(const char* input) {
            const int fil1 = ::fputs(input, logfile);
            if (fil1 < 0) {
                throw runtime_error("Failed to write data on file!");
            }
            const int fil2 = ::fputs("\n", logfile);
            if (fil2 < 0) {
                throw runtime_error("Failed to write data on file!");
            }
        }
};

void doSomeComputation() {   
    if ((1 + 1) != 2) {
        throw runtime_error("failure during doing some computation");
    }
}

void example() {
    LogFile* logfile = new LogFile("logfile.txt");

    logfile->fputs("log - 1");

    // Call a function that performs some computation and may throw 
    // an exception
    try {
        doSomeComputation();
    } catch(const runtime_error& e) {
        cerr << "exception caught" << endl;
    }

    logfile->fputs("log - 2");

    cout << "closing logfile" << endl;
}

int main(void) {
    cout << "Calling example()" << endl;
    example();
    cout << "After calling example()" << endl;
    return 0;
}