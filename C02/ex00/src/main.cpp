#include <iostream>
#include "../include/Fixed.hpp"

std::string toBinary(int n)
{
    std::string r;
	if (n < 0)
		r = "1" +r;
	else
		r = "0" + r;
    while(n!=0)
	{
		r = (n % 2 == 0 ? "0" : "1") + r;
		n/=2;
	}
    return r;
}

int main( void ) {

	Fixed a;
	Fixed b( a );
	Fixed c;
	
	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}