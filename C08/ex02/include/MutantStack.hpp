/*
TODO:

[x] Write a MutantStack class.
[x] It will be implemented in terms of a std::stack.
[x] It will offer all its member functions, plus an additional feature:
iterators
[x] Write and turn in your own tests to ensure everything works as
expected.
*/

#pragma once

#include "../include/colors.hpp"

#include <deque>
#include <iostream>
#include <list>
#include <stack>

template <typename T> class MutantStack : public std::stack<T> {
  public:
    MutantStack() {};
    MutantStack(const MutantStack<T> &other) : MutantStack<T>::stack(other){};
    MutantStack &operator=(const MutantStack &rhs) {
		if (this != &rhs) // this->MutantStack<T>::stack::operator=(rhs);
			this->c = rhs.c;
		return(*this);
	}
    virtual ~MutantStack() {};
    typedef typename std::deque<T>::iterator iterator;

    iterator begin() { return this->c.begin(); };
    iterator end() { return this->c.end(); };
};
