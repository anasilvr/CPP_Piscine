#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>

#include <sys/time.h>
#include <stdio.h>
#include <time.h>

using std::string;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::list;
using std::stoi;

#define GRN "\e[0;32m"
#define RED "\e[0;31m"
#define NC "\e[0m"

class PmergeMe {
	public:
		PmergeMe(char **av);
		~PmergeMe();

	private:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &rhs);

		void msortVector(int start, int end);
		void msortList(int start, int end);
		void mergeVectors(int start, int mid, int end);
		void mergeLists(int start, int mid, int end);

		vector<int>	_vectCont;
		list<int>	_listCont;

		
};