#include "../include/Whatever.hpp"

int main( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << "\n\tExtra tests for fun:" << std::endl;
	char e = 'a';
	char f = 'z';
	::swap(c, d);
	std::cout << "\te = " << e << ", f = " << f << std::endl;
	std::cout << "\tmin( e, f ) = " << ::min( e, f ) << std::endl;
	std::cout << "\tmax( e, f ) = " << ::max( e, f ) << std::endl;
	std::cout << "\n";
	float g = 21.0f;
	float h = 'z';
	::swap(g, h);
	std::cout << "\tg = " << g << ", h = " << h << std::endl;
	std::cout << "\tmin( g, h ) = " << ::min( g, h ) << std::endl;
	std::cout << "\tmax( g, h ) = " << ::max( g, h ) << std::endl;
	return 0;
}