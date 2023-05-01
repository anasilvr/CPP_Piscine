#include "../include/Fixed.hpp"

Fixed::Fixed( void ): _fixedNb(0) {
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed& copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
	return ;
}

Fixed::Fixed(const int nb) {
//	int sign;
	std::cout << "Int constructor called" << std::endl;
	this->_fixedNb = nb << this->_fraction;
	// sign = this->_fixedNb << this->_sign;
	// std::cout << "sign = " << sign << std::endl;
	return ;
}

Fixed::Fixed(const float nb) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixedNb = roundf(nb * (1 << this->_fraction));
	return ;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits( void ) const {
	return (this->_fixedNb);
}

void	Fixed::setRawBits( int const raw ) {
	this->_fixedNb = raw;
}

float	Fixed::toFloat( void ) const {
	return ((float)this->_fixedNb / (1 << this->_fraction));
}

int		Fixed::toInt( void ) const
{
	return (this->_fixedNb >> this->_fraction);
}

Fixed& Fixed::operator=(Fixed const &rhs) { 
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedNb = rhs.getRawBits();
	return (*this);
}

const int Fixed::_fraction = 8;
//const int Fixed::_sign = 4;

std::ostream& operator<<(std::ostream& out, Fixed const& arg) {
	out << arg.toFloat();
	return (out);
}