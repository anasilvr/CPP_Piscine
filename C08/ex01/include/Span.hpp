/*
TODO:
[x] Develop a Span class that can store a maximum of N integers.
	[x] N is an unsigned int and will be the only parameter passed to the constructor.
[x] function called addNumber() to add a single number to the Span.
	[x] Any attempt to add a new element if there are already N elements stored should throw an exception.

[ ] Member functions: 
	[ ] function called addNumber() to add a single number to the Span.
		[ ] Any attempt to add a new element if there are already N elements stored should throw an exception.
	[ ] shortestSpan()
	[ ] longestSpan()
	[ ] fill your Span using a range of iterators: implement a member function to add many numbers to your Span in one call.

[x] If there are no numbers stored, or only one, no span can be found. (EXCEPTION)


Of course, you will write your own tests and they will be way more thorough than the
ones below. Test your Span at least with a minimum of 10 000 numbers. More would be
even better.
*/

#pragma once

#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <iostream>
#include "../include/colors.hpp"

using std::cout;
using std::endl;
using std::vector;

// Class declaration
class Span {
	public:
	/* CANON */
	Span();
	Span(unsigned int size);
	Span(const Span &other);
	Span &operator=(const Span &rhs);
	~Span();

	/* GETTERS */


  	/* MEMBERS FUNCTIONS */
	void				addNumber(const int element);
	void				addNumber(const std::vector<int>::iterator& begin, const std::vector<int>::iterator& end);
	unsigned int		shortestSpan() const;
	unsigned int		longestSpan() const;

	/* EXCEPTIONS */
	class InvalidSpan : public std::exception {
		public:
    const char *what() const throw();
};

	class FullSpan : public std::exception {
		public:
    const char *what() const throw();
};

	private:
	vector<int> _span;
	const unsigned int _size;
  
};
