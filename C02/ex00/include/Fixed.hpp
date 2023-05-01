#pragma once
#include <iostream>

class Fixed {

	public:
		Fixed	( void );					// Default Constructor
		Fixed	(const Fixed& copy);		// Copy Constructor
		~Fixed	( void );					// Destructor

		//Getters
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
	
		Fixed& operator=(Fixed const &rhs);	// Operator overload

	private:
		int		_fixedNb;
		static int const _fraction;
};

std::ostream& operator<<(std::ostream& out, Fixed const& arg);
