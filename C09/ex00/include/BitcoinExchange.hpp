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

// Class declaration
class BitcoinExchange {
	public: 
		BitcoinExchange(const char *argv);
		~BitcoinExchange();
	
	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &rhs);

	//	void	parseInput();
		void	parseData();
		void	compareData() const;
		void	generateOutput(const char *av) const;
		void	errMsg (string msg, string data);

		string _filename;
		string _dataBuffer;

	//	multimap<string, string> _inputMap;
		map<string, float> _dataMap;
};


