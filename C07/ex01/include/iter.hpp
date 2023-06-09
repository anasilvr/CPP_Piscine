/*
TODO:
[x] Implement a function template iter that takes 3 parameters and returns
nothing. [x] First parameter: address of an array. [x] Second parameter: length
of the array. [x] Third parameter:a function that will be call on every element
of the array.

[c] Turn in a main.cpp file that contains your tests.
[x] Your iter function template must work with any type of array.
    The third parameter can be an instantiated function template.
*/

#pragma once

#include <iomanip>
#include <iostream>

template <typename T> void iter(T *array, size_t len, void (*f)(const T &))
{
    for (size_t i = 0; i < len; i++) {
        (*f)(array[i]);
    }
}

template <typename T> void print(T const &content)
{
    std::cout << content << std::endl;
}