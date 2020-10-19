#include "stack.h"
#include <iostream>

using namespace std ;

 // check whether the stack is empty
bool Stack::empty() {
    return _top == -1;
}
 // check whether the stack is full
bool Stack::full() {
    return _top == _max_size;
}

 // return the number of elements
int Stack::size() {
    return _top > -1 ? _top : 0;
}

 // insert element on top
 // print an error message on std::cerr when overflow
void Stack::push(int x) {
    if(_top==_max_size){
       cerr << "Stack overflow!!" << endl;
       return;
    }
    _top=_top+1;
    _data[_top]=x;
}

 // remove element on top
 // print an error message on std::cerr when underflow
void Stack::pop() {
    if(_top==-1){
       cerr << "Stack underflow!!" << endl;
       return;
    }
    cout << _data[_top] << endl;
    _top--;
}

 // acces the topmost element
 int Stack::top() {
    return _data[_top];
 }
 