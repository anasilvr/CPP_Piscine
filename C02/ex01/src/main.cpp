#include <iostream>
#include "../include/Fixed.hpp"

// std::string toBinary(int n)
// {
//     std::string r;
// 	if (n < 0)
// 		r = "1" +r;
// 	else
// 		r = "0" + r;
//     while(n!=0)
// 	{
// 		r = (n % 2 == 0 ? "0" : "1") + r;
// 		n/=2;
// 	}
//     return r;
// }

int main( void ) 
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	Fixed const e( -10 );

	a = Fixed( 1234.4321f );
	
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

//	std::cout << "a._fixedNb = " << a.getRawBits() << std::endl;
//	std::cout << "Binary = " << toBinary(a.getRawBits()) << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;

//	std::cout << "b._fixedNb = " << b.getRawBits() << std::endl;
//	std::cout << "Binary = " << toBinary(b.getRawBits()) << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;

//	std::cout << "c._fixedNb = " << c.getRawBits() << std::endl;
//	std::cout << "Binary = " << toBinary(c.getRawBits()) << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;

//	std::cout << "d._fixedNb = " << d.getRawBits() << std::endl;
//	std::cout << "Binary = " << toBinary(d.getRawBits()) << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	// std::cout << "e._fixedNb = " << e.getRawBits() << std::endl;
	// std::cout << "Binary = " << toBinary(e.getRawBits()) << std::endl;
	std::cout << "e is " << e.toInt() << " as integer" << std::endl;
	return 0;
}