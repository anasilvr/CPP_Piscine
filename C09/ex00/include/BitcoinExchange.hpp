#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <utility>

using std::string;
using std::cout;
using std::cerr;
using std::endl;
using std::map;

#define GRN "\e[0;32m"
#define RED "\e[0;31m"
#define NC "\e[0m"

// Class declaration
class BitcoinExchange {
	public: 
		BitcoinExchange(const char *argv);
		~BitcoinExchange();
	
	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &rhs);

		void		parseData();

		bool	isDateValid(string date) const;
		int 	dateToInt(string date) const;
		void	generateOutput(const char *av) const;

		string _dataBuffer;

		map<int, float> _dataMap;
};


