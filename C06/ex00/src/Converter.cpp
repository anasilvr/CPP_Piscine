
#include "../include/Converter.hpp"

// Default constructor
// Converter::Converter() { return; }

Converter::Converter(const string arg) : _literal(arg) {
    if (arg.empty()) throw Invalid();

    _cLiteral = arg.c_str();
    _len      = _literal.length();
    // cout << YEL "Converter creation with arg [" << _literal << "] ";

    // cout << "] and ASCII value of [";
    // for (int i = 0; _cLiteral[i]; i++)
    //     cout << " " << static_cast<int>(_cLiteral[i]) << " ";
    // cout << "]" << NC << endl;

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

void Converter::detectType(void) {
    if (_len == 1) {
        if (isdigit(_literal.front())) {
            _intConv = stoi(_literal);
            _argType = INT;
        } else {
            _charConv = _cLiteral[0];
            _argType  = CHAR;
        }
        return;
    }

    else if (!_literal.compare("-inff") || !_literal.compare("+inff") ||
             !_literal.compare("nanf") || !_literal.compare("-inf") ||
             !_literal.compare("+inf") || !_literal.compare("nan")) {
        _argType = PSEUDO;
		
    } else {
        int dot = -1;
        int f   = -1;
        for (int i = 0; _cLiteral[i]; i++)
            if (_cLiteral[i] == 'f') f++;
        for (int i = 0; _cLiteral[i]; i++)
            if (_cLiteral[i] == '.') dot++;
        if (dot > 0 || f > 0) throw(Invalid());
        if (_literal.find_first_not_of("-+0123456789.f") != string::npos)
            throw(Invalid());
        if (f == 0) {
            f = _literal.find_first_of("f");
            if (f == (static_cast<int>(_len) - 1)) {
                _floatConv = strtof(_cLiteral, NULL);
                _argType   = FLOAT;
                return;
            } else
                throw(Invalid());
        } else if (dot == 0) {
            _doubleConv = strtod(_cLiteral, NULL);
            _argType    = DOUBLE;
            return;
        } else {
            long test = strtol(_cLiteral, NULL, 10);
            if (test > INT_MAX || test < INT_MIN)
                throw(Invalid());
            else {
                _intConv = static_cast<int>(test);
                _argType = INT;
            }
        }
    }
}

char Converter::toChar(void) const {
    switch (_argType) {
        case CHAR:
            return (_charConv);

        case INT:
            if (_intConv >= CHAR_MAX || _intConv < CHAR_MIN)
                throw(Impossible());
            if (!isprint(_intConv))
                throw(NonDisplayable());
            else
                return (static_cast<char>(_intConv));

        case FLOAT:
            if (isnan(_floatConv) || isinf(_floatConv) ||
                _floatConv >= CHAR_MAX || _floatConv < CHAR_MIN)
                throw(Impossible());
            else if (!isprint(_floatConv))
                throw(NonDisplayable());
            else
                return (static_cast<char>(_floatConv));

        case DOUBLE:
            if (isnan(_doubleConv) || isinf(_doubleConv) ||
                _doubleConv >= CHAR_MAX || _doubleConv < CHAR_MIN)
                throw(Impossible());
            else if (!isprint(_doubleConv))
                throw(NonDisplayable());
            else
                return (static_cast<char>(_doubleConv));

        case PSEUDO:
            throw(Impossible());
    }
}

int Converter::toInt(void) const {
    switch (_argType) {
        case CHAR:
            return (static_cast<int>(_charConv));

        case INT:
            return (_intConv);

        case FLOAT:
            if (_floatConv >= INT_MAX || _floatConv < INT_MIN)
                throw(Impossible());
            else
                return (static_cast<int>(_floatConv));

        case DOUBLE:
            if (_doubleConv >= INT_MAX || _doubleConv < INT_MIN)
                throw(Impossible());
            else
                return (static_cast<int>(_doubleConv));

        case PSEUDO:
            throw(Impossible());
    }
}

float Converter::toFloat(void) const {
    switch (_argType) {
        case CHAR:
            return (static_cast<float>(_charConv));

        case INT:
            return (static_cast<float>(_intConv));

        case FLOAT:
            return (_floatConv);

        case DOUBLE:
            return (static_cast<float>(_doubleConv));

        case PSEUDO:
            return (strtof(_cLiteral, NULL));
    }
}

double Converter::toDouble(void) const {
    switch (_argType) {
        case CHAR:
            return (static_cast<double>(_charConv));

        case INT:
            return (static_cast<double>(_intConv));

        case FLOAT:
            return (static_cast<double>(_floatConv));

        case DOUBLE:
            return (_doubleConv);

        case PSEUDO:
            return (strtod(_cLiteral, NULL));
    }
}
std::ostream &operator<<(std::ostream &out, Converter const &arg) {
    // CHAR
    out << "char: ";
    try {
        char c = arg.toChar();
        out << "'" << c << "'" << endl;
    } catch (std::exception &e) {
        out << e.what() << NC << endl;
    }
    // INT
    out << "int: ";
    try {
        int i = arg.toInt();
        out << i << endl;
    } catch (std::exception &e) {
        out << e.what() << NC << endl;
    }
    // FLOAT
    out << "float: ";
    try {
        float  f       = arg.toFloat();
        double intpart = modf(f, &intpart);
        if (intpart == 0) out.precision(1);
        out << std::fixed << f << "f" << endl;
    } catch (std::exception &e) {
        out << e.what() << NC << endl;
    }
    // DOUBLE
    out << "double: ";
    try {
        double d       = arg.toDouble();
        double intpart = modf(d, &intpart);
        if (intpart == 0) out.precision(1);
        out << std::fixed << d << std::endl;

    } catch (std::exception &e) {
        out << e.what() << NC << endl;
    }
    return (out);
}

const char *Converter::Invalid::what() const throw() {
    return ("Input is empty or invalid!");
}

const char *Converter::NonDisplayable::what() const throw() {
    return ("Non displayable");
}

const char *Converter::Impossible::what() const throw() {
    return ("impossible");
}