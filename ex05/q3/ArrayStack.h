// ArrayStack.h

#include <string>
#include <iostream>

#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

class ArrayStack {
    private:
    int _num_items; // number of items in the stack
    double* _items; // stack items
    int _allocated_size; // size of memory allocated

    void resize(int max_size) {
        if (max_size==0) max_size++;
        
        // Move stack to a new array of size max
        _allocated_size = max_size;
        double* temp = new double[max_size];
        // Copy 
        for (int i = 0; i < _num_items; ++i) {
            temp[i] = _items[i];
        }
        delete[] _items;
        _items = temp;
    }

public:
    // Constructors:1
    ArrayStack() : _num_items(0),_allocated_size(0),_items(nullptr){}
    /* COMPLETE ... init _num_items to 0, _allocated_size to 0, and
     * set _items to the null pointer, 
     */
    // Constructors:2
    explicit ArrayStack(int allocated_size) : _num_items(0),_allocated_size(allocated_size),_items(new double[allocated_size]){}
    /* COMPLETE ... init _num_items to 0, 
     * pre-allocate memory for an array of size allocated_size
     * and make _items point to it */
    // Constructors:3,4
    ArrayStack(const ArrayStack& arr1) :
        _num_items(arr1._num_items),
        _allocated_size(arr1._allocated_size), 
        _items(new double)
        {}

    // Constructors:5,6
    ArrayStack& operator=(const ArrayStack& arr2){
                delete[] _items;
                _num_items = arr2._num_items;
                _allocated_size = arr2._allocated_size;
                _items = new double[_allocated_size];
                *_items = *arr2._items;
                return *this;
            }

    //move const
    ArrayStack(ArrayStack&& arr3){
            _num_items = arr3._num_items;
            _allocated_size = arr3._allocated_size;
            _items = arr3._items;
            std::cout << "Move Constructor" << std::endl;
    }

    //move assignment
    ArrayStack& operator=(ArrayStack&& arr4){
            _num_items = arr4._num_items;
            _allocated_size = arr4._allocated_size;
            _items = arr4._items;
            std::cout << "Move Assignment" << std::endl;
        }
    // Destructor:
    ~ArrayStack() {
        // COMPLETE
        delete[] _items;
    }

    void push(double item) {
        if (_num_items == _allocated_size) resize(2*_allocated_size);
        _items[_num_items++] = item;
    }

    void pop() {
        _num_items--;
        if (_num_items > 0 && _num_items == _allocated_size/4) resize(_allocated_size/2);
    }

    double top() {
        return _items[_num_items-1];
    }

    bool empty() const { return _num_items == 0; }

    int size() const { return _num_items; }
};

#endif // ARRAY_STACK_H
