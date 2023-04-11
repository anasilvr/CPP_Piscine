#include "../include/Fixed.hpp"


Fixed::Fixed(): _fixedNb(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedNb);
}

void	Fixed::setRawBits( int const raw )
{
	this->_fixedNb = raw;
}


Fixed& Fixed::operator=(Fixed const &rhs)
{ 
	std::cout << "Copy assignment operator called" << std::endl;

	this->_fixedNb = rhs.getRawBits();
	return (*this);
}

const int Fixed::_fraction = 8;