#include "../include/Span.hpp"

/* ---------- CANON ---------- */
// Default constructor
Span::Span() : _size(0) { 
	cout << GRN "Span[" << _size << "] created." NC << endl;
	return;
}

Span::Span(unsigned int N) : _size(N) {
	cout << GRN "Span[" << _size << "] created." NC << endl;
	return;
}

// Copy constructor
Span::Span(const Span &other) : _size(other._size) {
  *this = other;
  return;
}

// Copy assignment overload
Span &Span::operator=(const Span &rhs) {
  if (this != &rhs) {
	_span = rhs._span;
	//copies all contents using iterator.
	// _N = rhs.nameofvector.size();
  }
  return *this;
}

// Default destructor
Span::~Span() { 
	cout << GRN "Span[" << _size << "] destroyed." NC << endl;
	return;
}


/* ---------- MEMBERS FUNCTIONS ---------- */
void				Span::addNumber(int element) {

	if (_span.size() == _size)
		throw FullSpan();
	else
		_span.push_back(element);

	cout << "\tspan size: " << _span.size();
	cout << "\tcontent: ";
	for (unsigned long i = 0; i < _span.size(); i++)
    	cout << _span.at(i) << " ";
	cout << endl;
}

void				Span::addNumber(const std::vector<int>::iterator& begin, const std::vector<int>::iterator& end) {
	int inputSize = std::distance(begin, end);
	if (inputSize + _span.size() > _size) {
		inputSize = _size - _span.size();
		_span.insert(_span.end(), begin, (begin + inputSize));
		throw FullSpan();
		}
	else
		_span.insert(_span.end(), begin, end);

	cout << "\tspan size: " << _span.size();
	cout << "\tcontent: ";
	for (unsigned long i = 0; i < _span.size(); i++)
    	cout << _span.at(i) << " ";
	cout << endl;
}

unsigned int		Span::shortestSpan() const {
	cout << "coucou" << endl;
	return (1);
}

unsigned int		Span::longestSpan() const {
	cout << "coucou" << endl;
	return (1);
}

/* ---------- EXCEPTIONS ---------- */
const char *Span::InvalidSpan::what() const throw() {
	return ("Not enough numbers stored.");
}


const char *Span::FullSpan::what() const throw() {
	return ("Span's container is already full.");
}