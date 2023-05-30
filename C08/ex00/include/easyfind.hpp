/*
TODO:

[x] ] Write a function template easyfind that accepts a type T. It takes two
parameters: [x] 1) type T [x] 2) an integer

Assuming T is a container of integers,
[x] This function has to find the first occurrence of the second parameter in
the first parameter. [x] If no occurrence is found, you can either throw an
exception or return an error value of your choice.
    ---> Choice: Throw an exception for the sake of being really explicit about
it. [x] If you need some inspiration, analyze how standard containers behave.

[x] Implement and turn in your own tests to ensure everything works as ex-
pected
*/

#pragma once

#include <iostream>

class NotFound : public std::exception {
  public:
    const char *what() const throw()
    {
        return ("Error: Element not found.");
    };
};

template <class T> typename T::iterator easyfind(T &container, int toFind)
{
    typename T::iterator i =
        std::find(container.begin(), container.end(), toFind);
    if (i != container.end())
        return (i);
    else
        throw NotFound();
}
