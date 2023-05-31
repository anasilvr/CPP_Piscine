#include "../include/Span.hpp"

template<typename T>
void message(T msg) { cout << msg << endl; }

int main()
{
	Span sp = Span(5);
	try {
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
//	sp.addNumber(10);
	} catch (std::exception &e) { std::cerr << e.what() << endl; }
	message(sp.shortestSpan());
	message(sp.longestSpan());
	Span test (sp);
	return (0);
}