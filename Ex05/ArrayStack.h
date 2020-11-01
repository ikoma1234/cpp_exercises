// ArrayStack.h
#include <string>
#include <iostream>
#include <utility>

#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

class ArrayStack {
    private:
    int _num_items; // number of items in the stack
    int* _items; // stack items
    int _allocated_size; // size of memory allocated

    void resize(int max_size) {
        if (max_size==0) max_size++;
        
        // Move stack to a new array of size max
        _allocated_size = max_size;
        int* temp = new int[max_size];
        // Copy 
        for (int i = 0; i < _num_items; ++i) {
            temp[i] = _items[i];
        }
        delete[] _items;
        _items = temp;
    }

public:
    // Constructors:
    ArrayStack() : _num_items(0), _allocated_size(0), _items(nullptr) {
    /* COMPLETE ... init _num_items to 0, _allocated_size to 0, and
     * set _items to a null pointer, 
     */
    }


    explicit ArrayStack(int allocated_size) : _num_items(0), _allocated_size(allocated_size) {
    /* COMPLETE ... init _num_items to 0, 
     * pre-allocate memory for an array of size allocated_size
     * and make _items point to it 
     */
        _items = new int[_allocated_size];
    }

    // Destructor
    ~ArrayStack() {
        delete[] _items;
    }

    /* copy constructor */
    ArrayStack(ArrayStack& obj) : _num_items(obj._num_items), _allocated_size(obj._allocated_size) {
        std::cout << "Copy constructor" << std::endl;

        obj._num_items = 0;
        _items = new int[_allocated_size];
        for(int i = 0; i < _num_items; i++){
            _items[i] = obj._items[i];
        }
    }

    /* move construntor */
    ArrayStack(ArrayStack&& obj) : _num_items(obj._num_items), _allocated_size(obj._allocated_size) {
        std::cout << "Move constructor" << std::endl;
        _items = obj._items;
        
        obj._num_items=0;
        obj._allocated_size=0;
        obj._items=nullptr;
    }

    ArrayStack& operator=(ArrayStack& obj) {
        std::cout << "copy operator" << std::endl;
        if(this == &obj) return *this;
        delete[] _items;
        _num_items = obj._num_items;
        _allocated_size = obj._allocated_size;
        _items = new int[_allocated_size];
        for(int i = 0; i < _num_items; i++){
            _items[i] = obj._items[i];
        }
        return *this;
    }
    
    ArrayStack& operator=(ArrayStack&& obj) {
        std::cout << "move operator" << std::endl;
        if(this == &obj) return *this;
        delete[] _items;
        _num_items = obj._num_items;
        _allocated_size = obj._allocated_size;
        _items = obj._items;

        //make all variables of obj be stolen 
        obj._num_items = 0;
        obj._allocated_size = 0;
        obj._items = nullptr;
        return *this;
    }

    void push(int item) {
        if (_num_items == _allocated_size) resize(2*_allocated_size);
        _items[_num_items++] = item;
    }

    int pop() {
        int ret = _items[--_num_items];
        if (_num_items > 0 && _num_items == _allocated_size/4) resize(_allocated_size/2);
        return ret;
    }

    bool empty() const { 
        return _num_items == 0; 
    }

    int size() const {
         return _num_items;
    }
};

#endif // ARRAY_STACK_H