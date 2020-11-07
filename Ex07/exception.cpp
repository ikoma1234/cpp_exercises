   // exception.cpp
   #include <stdexcept>
#include <cstdio>
#include <iostream>

using namespace std;

void doSomeComputation() {
   throw runtime_error("failure during doing some computation");
}

void example() {
   FILE* logfile = fopen("logfile.txt", "w+");
   if (!logfile) {
      throw runtime_error("failed to open file");
   }

   fputs("log1", logfile);

   // call a function that performs some computation and may throw 
   // an exception
   try {
      doSomeComputation();
   }
   catch(const runtime_error& e) {

      cout << "Exception was caught in doSomeComputation()" << endl;

      fclose(logfile);
      throw;
   }
   cout << "closing logfile" << endl;
   fclose(logfile);
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