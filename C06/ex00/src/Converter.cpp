
#include "../include/Converter.hpp"

// Default constructor
// Converter::Converter() { return; }

Converter::Converter(const string arg) : _literal(arg) {
	if (arg.empty())
		throw Invalid();
	
	_cLiteral = arg.c_str();
	_len = arg.length();
    // cout << YEL "Converter creation with arg [" << _literal << "] ";
	// cout << " of lenght [" << _len;
	
	// cout << "] and ASCII value of [";
	// for (int i = 0; _cLiteral[i]; i++)
	// 	cout << " " << static_cast<int>(_cLiteral[i]) << " ";
	// cout << "]" << NC << endl;
	cout << WHTHB "Debug messages:" << NC << endl;
	detectType();
    return;
}

// // Copy constructor
// Converter::Converter(const Converter &other) {
//     *this = other;
//     return;
// }

// // Copy assignment overload
// Converter &Converter::operator=(const Converter &rhs) {
//     return *this;
// }

// Default destructor
Converter::~Converter() {
    return;
}

const string Converter::getLiteral(void) const {
    return (_literal);
}

void	Converter::detectType(void) {

	if (_len == 1) {
		if (isdigit(_literal.front())) {
			_intConv = static_cast<int>(stoi(_literal));
			_argType = INT;
		}
		else {
			_charConv = static_cast<char>(_literal.front());
			_argType = CHAR;
		}
	}
	else {
		char 	*remL;
		long	retL = strtol(_cLiteral, &remL, 10);
		char 	*remD;
		double	retD = strtod(_cLiteral, &remD); 
		
		// cout << WHTHB "retL = " << retL << NC << endl;
		// cout << WHTHB "retD = " << retD << NC << endl;
		
		if (*remL){
			for (int i = 0; remL[i]; i++)
				_precision++;
		//	cout << WHTHB "remL = " << remL << NC << endl;
			if (*remD) {
		//		cout << WHTHB "remD = " << remD << NC << endl;
				if (*remD == 'f') {
					_floatConv = static_cast<float>(retD);
					_argType = FLOAT;
				}
				else
					throw (Invalid());
			}
			else {
				_doubleConv = retD;
				_argType = DOUBLE;
			}
		}
		else {
			if (retL > INT_MAX || retL < INT_MIN)
				throw (Invalid());
			else {
				_intConv = static_cast<int>(retL);
				_argType = INT;
			}
		}
	}
}

char Converter::toChar(void) const {
	char value = 0;
	switch (_argType) {

		case CHAR:
			return (_charConv);

		case INT:
			value = static_cast<char>(_intConv);
			if (!isprint(value))
				throw (NonDisplayable());
			else
				return(value);

		case FLOAT:
			value = static_cast<float>(_floatConv);
			if (isnan(_floatConv) || isinf(_floatConv))
				throw (Impossible());
			else if (!isprint(value))
				throw (NonDisplayable());
			else
				return (value);

		case DOUBLE:	
			value = static_cast<double>(_doubleConv);
			if (isnan(_doubleConv) || isinf(_doubleConv))
				throw (Impossible());
			else if (!isprint(value))
				throw (NonDisplayable());
			else
				return (value);
	}
}

int Converter::toInt(void) const {
	switch (_argType) {

		case CHAR:
			return (static_cast<int>(_charConv));

		case INT:
			return(_intConv);

		case FLOAT:
			if (isnan(_floatConv) || isinf(_floatConv) ||
				_floatConv > INT_MAX || _floatConv < INT_MIN)
				throw (Impossible());
			else
				return (static_cast<int>(_floatConv));

		case DOUBLE:	
			if (isnan(_doubleConv) || isinf(_doubleConv) ||
				_doubleConv > INT_MAX || _doubleConv < INT_MIN)
				throw (Impossible());
			else
				return (static_cast<int>(_doubleConv));
	}
}

float Converter::toFloat(void) const {
	switch (_argType) {
		case CHAR:
			return (static_cast<float>(_charConv));

		case INT:
			return(static_cast<float>(_intConv));

		case FLOAT:
			return (static_cast<float>(_floatConv));

		case DOUBLE:	
			return (_doubleConv);
	}
}

double Converter::toDouble(void) const {
	switch (_argType) {
		case CHAR:
			return (static_cast<float>(_charConv));

		case INT:
			return(static_cast<float>(_intConv));

		case FLOAT:
			return (_floatConv);

		case DOUBLE:	
			return (static_cast<float_t>(_doubleConv));
	}
}
std::ostream& operator<<(std::ostream& out, Converter const& arg){
//CHAR
	out << "char: '";
	try {
		const char c = arg.toChar();
		out << c << "'" << endl;
	}
    catch (std::exception &e) {
		out << e.what() << NC << endl;
	}
//INT
	out << "int: ";
	try {
		const int i = arg.toInt();
		out << i << endl;
	}
    catch (std::exception &e) {
		out << e.what() << NC << endl;
	}
//FLOAT
	out << "float: ";
	try {
		float f = arg.toFloat();
		double fract = f - floor(f);
		out << f << fract << "f" << std::endl;
	}
    catch (std::exception &e) {
		out << e.what() << NC << endl;
	}
//DOUBLE
	out << "double: ";
	try {
		double d = arg.toDouble();
		double fract = d - floor(d);
		out << d << fract <<"f" << std::endl;
	}
    catch (std::exception &e) {
		out << e.what() << NC << endl;
	}
    return (out);
}

const char *Converter::Invalid::what () const throw () {
	return ("Input is empty or invalid!");
}

const char *Converter::NonDisplayable::what () const throw () {
	return ("Non displayable");
}

const char *Converter::Impossible::what () const throw () {
	return ("impossible");
}