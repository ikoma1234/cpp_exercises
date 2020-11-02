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
        throw invalid_argument("the input can not be converted");
    }

    char left;
    instream >> left;
    if (!instream.fail()) {
        // Error: there are some characters left after the int
        throw invalid_argument("there are some characters left after the int");
    }

  // everything went fine: returns the int
    return number;
 }

int main(void) {

  string test1 = "11";
  try{
      cout << stringToInt(test1) << endl;
  }
  catch(invalid_argument& err){
      cout << err.what() << '\n';
  }  
 
  string test2 = "cc11";
  try{
      cout << stringToInt(test2) << endl;
  }
  catch(invalid_argument& err){
      cout << err.what() << '\n';
  }

  string test3 = "11cc";
  try{
      cout << stringToInt(test3) << endl;
  }
  catch(invalid_argument& err){
      cout << err.what() << '\n';
  }

  cout << "Tests passed" << endl;

  return 0;
}