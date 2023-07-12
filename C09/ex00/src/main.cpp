/*
TODO:

[x] Create a program which outputs the value of a certain amount of bitcoin on
a certain date.
[x] Use a database in csv format which will represent bitcoin
price over time.
[x] The program will take as input a second database, storing
the different prices/dates to evaluate.

Your program must respect these rules:
    [x] The program name is btc.
    [x] Your program must take a file as argument.
        [x] Each line in this file must use the following format: "date | value"
		[x] A valid date will always be in the following format: Year-Month-Day [Error: bad input => 2001-42-42]
        [x] A valid value must be either a float or a positive integer
		between 0 and 1000. [Error: not a positive number.] // [Error: too large a number.]

[x] STDOUT: the result of the value multiplied by the exchange rate according
to the date indicated in your database. [x] If the date used in the input does
not exist in your DB then you must use the closest date contained in your DB
[x] Be careful to use the lower date and not the upper one.

[x] You must use at least one container in your code to validate this (map)
[x] You should handle possible errors with an appropriate error message.
[x] Validate file permissions
*/

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/BitcoinExchange.hpp"

static void verifyFile(string f) {
	std::ifstream file(f);
	if (!file.fail()) {
		file.seekg(0,std::ios::end);
		size_t size = file.tellg();
		if (!size) {
			cerr << RED "File [" << f << "] is empty.\nExiting..." NC << endl;
			file.close();
			exit(EXIT_FAILURE);
		}	
		cout << GRN "File [" << f << "] is valid." NC << endl;
		file.close();
	}
	else {
		cerr << RED "Error opening [" << f << "]\nExiting..." NC << endl;
		file.close();
		exit(EXIT_FAILURE);
	}
}

int main (int ac, char **av) {
	if (ac == 2) {
		verifyFile(av[1]);
		verifyFile("data.csv");
		cout << endl;
		BitcoinExchange out (av[1]);
	}
	else{
		cerr << RED "Invalid number of arguments.\nUsage: \"./btc [reference_file.txt]\"" NC << endl;
		return (EXIT_FAILURE);
	}
}