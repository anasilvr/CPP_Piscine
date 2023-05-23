#pragma once

#include <iomanip>
#include <iostream>

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

    void   detectType(void);
    char   toChar(void) const;
    int    toInt(void) const;
    float  toFloat(void) const;
    double toDouble(void) const;

   private:
    Converter();
    Converter(const Converter &other);
    Converter &operator=(const Converter &rhs);

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

    enum type {
        CHAR,
        INT,
        FLOAT,
        DOUBLE,
        PSEUDO,
    };

    const string _literal;
    const char  *_cLiteral;
    size_t       _len;
    type         _argType;

    char   _charConv;
    int    _intConv;
    float  _floatConv;
    double _doubleConv;
    string _pseudo;
};

std::ostream &operator<<(std::ostream &out, Converter const &arg);