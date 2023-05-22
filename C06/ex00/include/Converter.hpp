#pragma once

#include <iostream>
#include <iomanip>

#include "../include/colors.hpp"

using std::cout;
using std::endl;
using std::string;

#define ERR_MSG (std::cerr << RED "Error: " << e.what() << NC << endl)

// Class declaration
class Converter {
   public:
    Converter(const string arg);
    ~Converter();

	void	detectType(void);
	char	toChar(void) const;
	int		toInt(void) const;
	float	toFloat(void) const;
	double	toDouble(void) const;
   
   private:
    enum type {
        CHAR,
        INT,
        FLOAT,
        DOUBLE,
    };

    Converter();
    Converter(const Converter &other);
    Converter &operator=(const Converter &rhs);

    const string getLiteral(void) const;



	class Invalid : public std::exception {
		public:
			const char *what() const throw();
	};

	class NonDisplayable : public std::exception {
		public:
			const char *what() const throw();
	};

	class Impossible : public std::exception {
		public:
			const char *what() const throw();
	};

    const string _literal;
	const char* _cLiteral;
	size_t	_len;

	char _charConv;
	int	_intConv;
	float _floatConv;
	double	_doubleConv;
	int	_precision;
	
    type          _argType;
};

std::ostream& operator<<(std::ostream& out, Converter const& arg);