#pragma once
#include <iostream>
#include <cmath>

class Fixed {

	public:
		Fixed	( void );					// Default Constructor
		Fixed	(const Fixed& copy);		// Copy Constructor
		Fixed	(const int nb);
		Fixed	(const float nb);
		~Fixed	( void );					// Destructor

		//Getter/Setter
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
	
		float	toFloat( void ) const;
		int		toInt( void ) const;

		static			Fixed& 	min (Fixed& a, Fixed& b);
		static const	Fixed& 	min (Fixed const& a, Fixed const& b);
		static			Fixed& 	max (Fixed& a, Fixed& b);
		static const	Fixed& 	max (Fixed const& a, Fixed const& b);

		// Operator overloads
		Fixed& operator=(Fixed const &rhs); // Assignement (or Copy) operator

		//Comparison operators
		bool operator>(Fixed const &rhs);
		bool operator<(Fixed const &rhs);
		bool operator>=(Fixed const &rhs);
		bool operator<=(Fixed const &rhs);
		bool operator==(Fixed const &rhs);
		bool operator!=(Fixed const &rhs);

		//Arithmetic operators
		Fixed operator+(Fixed const &rhs);
		Fixed operator-(Fixed const &rhs);
		Fixed operator*(Fixed const &rhs);
		Fixed operator/(Fixed const &rhs);

		//Increment/decrement operators
		Fixed& operator++( void );
		Fixed& operator--( void );
		Fixed& operator++( int );
		Fixed& operator--( int );



	private:
		int					_fixedNb;
		static int const	_fraction;
};

std::ostream& operator<<(std::ostream& out, Fixed const& arg);
