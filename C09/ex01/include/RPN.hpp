#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <utility>

using std::string;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::stack;

#define GRN "\e[0;32m"
#define RED "\e[0;31m"
#define NC "\e[0m"

class RPN {
	public:
		RPN (const char *av);
		~RPN();

	private:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &rhs);

		void	verifyInputContent();
		void	verifyInputFormat();
		void	calculate();

		string			_raw;
		size_t			_opCount;
		size_t			_nbCount;
		size_t			_iLen;
		stack<float>	_cstk;
};