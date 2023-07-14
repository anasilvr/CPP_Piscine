#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using std::string;
using std::cout;
using std::cerr;
using std::endl;

#define GRN "\e[0;32m"
#define RED "\e[0;31m"
#define NC "\e[0m"

class PmergeMe {
	public:
		PmergeMe();
		~PmergeMe();

	private:
	//	PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &rhs);
};