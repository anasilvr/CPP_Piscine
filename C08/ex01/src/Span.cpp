#include "../include/Span.hpp"

/* ---------- CANON ---------- */
// Default constructor
Span::Span() : _size(0) { return ;}

Span::Span(unsigned int N) : _size(N) {	return; }

// Copy constructor
Span::Span(const Span &other) : _size(other._size) {
  *this = other;
  return;
}

// Copy assignment overload
Span &Span::operator=(const Span &rhs) {
  if (this != &rhs) { _span = rhs._span; }
  return *this;
}

// Default destructor
Span::~Span() { return; }


/* ---------- MEMBERS FUNCTIONS ---------- */
void				Span::addNumber(int element) {

	if (_span.size() == _size)
		throw FullSpan();
	else
		_span.push_back(element);
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
}

unsigned int		Span::shortestSpan() const {
	if (_size <= 1)
		throw(InvalidSpan());
	
	vector<int> tmp (_span);
	vector<int> diff;

	std::sort(tmp.begin(), tmp.end());
	std::adjacent_difference(tmp.begin(), tmp.end(), std::back_inserter(diff));
	return (*std::min_element(diff.begin(), diff.end()));
}

unsigned int		Span::longestSpan() const {
	if (_size <= 1)
		throw(InvalidSpan());
	int max = *std::max_element(_span.begin(), _span.end());
	int min = *std::min_element(_span.begin(), _span.end());
	return (max - min);
}

/* ---------- EXCEPTIONS ---------- */
const char *Span::InvalidSpan::what() const throw() {
	return ("Not enough numbers stored.");
}


const char *Span::FullSpan::what() const throw() {
	return ("Span is already full.");
}

	// cout << "\t[container] size: " << [container].size();
	// cout << "\tcontent: ";
	// for (unsigned long i = 0; i < [container].size(); i++)
    //		cout << [container].at(i) << " ";
	// cout << endl;