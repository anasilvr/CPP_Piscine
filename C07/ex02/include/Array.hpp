/*
TODO:

[x] Develop a class template Array that contains elements of type T and that
implements the following behavior and functions:

    [x] Construction with no parameter: Creates an empty array.
    [x] Construction with an unsigned int n as a parameter: Creates an array of
n elements initialized by default. (Tip: Try to compile int * a = new int();
then display *a.) [x] Construction by copy and assignment operator. In both
cases, modifying either the original array or its copy after copying musn’t
affect the other array. [x] You MUST use the operator new[] to allocate memory.
Preventive allocation (al- locating memory in advance) is forbidden. Your
program must never access non- allocated memory. [x] Elements can be accessed
through the subscript operator: "[ ]". [x] When accessing an element with the
"[ ]"" operator, if its index is out of bounds, an std::exception is thrown.
    [x] A member function size() that returns the number of elements in the
array. This member function takes no parameter and musn’t modify the current
instance.

[x] As usual, ensure everything works as expected and turn in a main.cpp file
that con- tains your tests.

*/

#pragma once

#include <iomanip>
#include <iostream>

template <typename T> class Array {
  public:
    Array() : _arr(new T[0]), _size(0)
    {
        return;
    }
    Array(unsigned int N) : _arr(new T[N]), _size(N)
    {
        return;
    }
    Array(const Array &other)
    {
        _size = other._size;
        _arr = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            _arr[i] = other._arr[i];
        return;
    }
    Array &operator=(const Array &rhs)
    {
        if (this != &rhs) {
            delete[] this->_arr;
            _size = rhs._size;
            _arr = new T[_size];
            for (unsigned int i = 0; i < _size; i++)
                _arr[i] = rhs._arr[i];
        }
        return *this;
    }
    ~Array()
    {
        delete[] _arr;
    };

    unsigned int size() const
    {
        return (_size);
    };

    T &operator[](unsigned int i)
    {
        if (i >= _size)
            throw(Array<T>::OutOfBounds());
        return _arr[i];
    };

    class OutOfBounds : public std::exception {
      public:
        const char *what() const throw()
        {
            return ("Index error: Out of bounds");
        };
    };

  private:
    T *_arr;
    unsigned int _size;
};
