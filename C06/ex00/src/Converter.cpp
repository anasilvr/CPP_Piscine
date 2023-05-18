
#include "../include/Converter.hpp"

// Default constructor
// Converter::Converter() { return; }

Converter::Converter(const string &arg) : _literal(arg), _argType(NOTSET) {
    cout << YEL "Converter creation with arg: " << _literal << NC << endl;
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

const string Converter::getLiteral(void) {
    return (_literal);
}

void Converter::detectType(void) {
    funcPtr checker = {&Converter::isChar, &Converter::isInt,
                       &Converter::isFloat, &Converter::isDouble};

    for (int i = 0; _argType == NOTSET && i < 4; i++) {
        (this->*checker[i])();
    }

    if (_argType == NOTSET) _argType = INVALID;
    cout << "Type is " << _argType << endl;
}

void Converter::isChar(void) {
}

void Converter::isInt(void) {
}

void Converter::isFloat(void) {
    if (!_literal.compare("-inff") || !_literal.compare("+inff") ||
        !_literal.compare("nanf"))
        _argType = PSEUDO;
}

void Converter::isDouble(void) {
    if (!_literal.compare("-inf") || !_literal.compare("+inf") ||
        !_literal.compare("nan"))
        _argType = PSEUDO;
}
