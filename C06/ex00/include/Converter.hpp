#pragma once

#include <iostream>

#include "../include/colors.hpp"

using std::cout;
using std::endl;
using std::string;

#define ERR_MSG (std::cerr << RED "Error: " << e.what() << NC << endl)

// Class declaration
class Converter {
   public:
    Converter(const string &arg);
    ~Converter();

   private:
    enum type {
        CHAR,
        INT,
        FLOAT,
        DOUBLE,
        PSEUDO,
        NOTSET,
        INVALID,
    };

    Converter();
    Converter(const Converter &other);
    Converter &operator=(const Converter &rhs);

    const string getLiteral(void);
    void         detectType(void);

    void isChar(void);
    void isInt(void);
    void isFloat(void);
    void isDouble(void);

    const string &_literal;
    type          _argType;
};

typedef void (Converter::*funcPtr[4])(void);