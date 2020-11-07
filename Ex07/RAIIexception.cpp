#include <stdexcept>
#include <cstdio>
#include <iostream>

using namespace std;

class LogFile {
public:
    bool isNullptr(){
        return _file == nullptr;
    }
    FILE* getFile(){
        return _file; 
    }
    LogFile(const char* file, const char* mode) : _file(nullptr) {
        _file = fopen(file, mode);
        cout << "Create file" << endl;
    }
    ~LogFile() {
        fclose(_file);
        cout << "Close file" << endl;
    }


private:
    FILE* _file;
};

void doSomeComputation() {
   throw runtime_error("failure during doing some computation");
}

void example() {
    LogFile Myfile("logfile.txt", "w+");
    if (Myfile.isNullptr()) {
        throw runtime_error("failed to open file");
    }

    fputs("testtesttesttest", Myfile.getFile());

    // call a function that performs some computation and may throw 
    // an exception
    try {
        doSomeComputation();
    }
    catch(const runtime_error& e) {
        cout << "Exception was caught in doSomeComputation()" << endl;
        throw;
    }
    cout << "closing logfile" << endl;
}

int main(void) {
    cout << "Calling example()" << endl;
    try {example();}
    catch(const runtime_error& e) {
        cout << e.what() << endl;
    }
    cout << "After calling example()" << endl;
    return 0;
}