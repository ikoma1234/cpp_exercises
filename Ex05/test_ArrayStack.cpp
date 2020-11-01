// test_ArrayStack.cpp
#include "ArrayStack.h"

int main(void) {
// Create an instance of ArrayStack named stack1 
//   using the default constructor
    ArrayStack stack1;
// Push 1,2,3,4,5 in this stack
    for(int i = 0; i < 5; i++){
        stack1.push(i+1);
    }

// Create another instance of ArrayStack named stack2
//   using the other constructor, specify an original size of 5
    ArrayStack stack2(5);
// Push 1,2,...,10 in this stack
    for(int i = 0; i < 10; i++){
        stack2.push(i+1);
    }
    // Copy
    ArrayStack stack3(stack1);
    ArrayStack stack4 = stack2;

    // Assignment
    ArrayStack stack5;
    stack5 = stack1;
    ArrayStack stack6(10);
    stack6 = stack6;

    // Move
    ArrayStack stack7 = std::move(stack5);
    stack6 = std::move(stack2);
    
    return 0;
}