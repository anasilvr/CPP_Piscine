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

	//Getters
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
	
		float	toFloat( void ) const;
		int		toInt( void ) const;

		Fixed& operator=(Fixed const &rhs);	// Operator overload

	private:
		int		_fixedNb;
		static int const _fraction;
};

std::ostream& operator<<(std::ostream& out, Fixed const& arg);
