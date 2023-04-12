#include "../include/Fixed.hpp"

const int Fixed::_fraction = 8;

Fixed::Fixed( void ): _fixedNb(0) {
	return;
}

Fixed::Fixed(const Fixed& copy) {
	*this = copy;
	return ;
}

Fixed::Fixed(const int nb) {
	this->_fixedNb = nb << this->_fraction;
	return ;
}

Fixed::Fixed(const float nb) {
	this->_fixedNb = roundf(nb * (1 << this->_fraction));
	return ;
}

Fixed::~Fixed(void) {
	return ;
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

int		Fixed::toInt( void ) const {
	return (this->_fixedNb >> this->_fraction);
}

Fixed& 	Fixed::min (Fixed& a, Fixed& b) {
	if (a < b)
		return a;
	return b;
}

const Fixed& 	Fixed::min (Fixed const& a, Fixed const& b) {
	if (a._fixedNb < b._fixedNb)
		return a;
	return b;
}

Fixed& 	Fixed::max (Fixed& a, Fixed& b) {
	if (a > b)
		return a;
	return b;
}

const Fixed& 	Fixed::max (Fixed const& a, Fixed const& b) {
	if (a._fixedNb > b._fixedNb)
		return a;
	return b;
}


// Operator overloads
Fixed& Fixed::operator=(Fixed const &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedNb = rhs.getRawBits();
	return (*this);
}

bool Fixed::operator>(Fixed const &rhs){
	return (this->_fixedNb > rhs._fixedNb);
}

bool Fixed::operator<(Fixed const &rhs) {
	return (this->_fixedNb < rhs._fixedNb);
}

bool Fixed::operator>=(Fixed const &rhs) {
	return (this->_fixedNb >= rhs._fixedNb);
}

bool Fixed::operator<=(Fixed const &rhs) {
	return (this->_fixedNb <= rhs._fixedNb);
}

bool Fixed::operator==(Fixed const &rhs) {
	return (this->_fixedNb == rhs._fixedNb);
}

bool Fixed::operator!=(Fixed const &rhs) {
	return (this->_fixedNb != rhs._fixedNb);
}

Fixed Fixed::operator+(Fixed const &rhs) {
	Fixed result;
	result.setRawBits(this->_fixedNb + rhs._fixedNb);
	return (result);
}

Fixed Fixed::operator-(Fixed const &rhs) {
	Fixed result;
	result.setRawBits(this->_fixedNb - rhs._fixedNb);
	return (result);
}

Fixed Fixed::operator*(Fixed const &rhs) {
	Fixed result;
	result.setRawBits(this->_fixedNb * rhs._fixedNb >> _fraction);
	return (result);
}

Fixed Fixed::operator/(Fixed const &rhs) {
	Fixed result;
	result.setRawBits(this->_fixedNb / rhs._fixedNb);
	return (result);
}

Fixed& Fixed::operator++( void ) {
	this->_fixedNb++;
	return (*this);
}

Fixed& Fixed::operator--( void ) {
	this->_fixedNb--;
	return (*this);
}

Fixed& Fixed::operator++( int ) {
	Fixed& tmp = *this;
	++*this;
	return(tmp);
}

Fixed& Fixed::operator--( int ) {
	Fixed& tmp = *this;
	--*this;
	return(tmp);
}



std::ostream& operator<<(std::ostream& out, Fixed const& arg)
{
	out << arg.toFloat();
	return (out);
}