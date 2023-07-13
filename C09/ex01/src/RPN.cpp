#include "../include/RPN.hpp"

RPN::RPN (const char *av) : _raw(av), _opCount(0), _nbCount(0) {
	verifyInput(av);
	_raw = av;
	parseInput();
	calculate();
}

RPN::~RPN() {}

void RPN::verifyInput(const char *av) {
	const char *validChar = "0123456789+-/* ";
	_iLen = _raw.length();
	bool isValid;
	(void) av;
	if (_iLen == 0 || _raw.find_first_not_of(" \n\t\v\r\f") == string::npos) {
		cout << RED "Error: Empty input" NC << endl;
		exit(EXIT_FAILURE);
	}

	for (size_t i = 0; i < _iLen; i++) {
		isValid = false;
		for (size_t j = 0; j < 15; j++) {
			if (_raw[i] == validChar [j]) {
				isValid = true ;
				j = 0;
				break ;
			}
		}
		if (isValid == false) {
			cout << RED "Error: Invalid character found" NC << endl;
			exit(EXIT_FAILURE);
		}
	}
}

static bool	isOperand(char c) {
	if (c >= '0' && c <= '9')
		return (true);
	return(false);
}

static bool	isOperator(char c) {
	if (c == '+' ||	c == '-' ||	c == '/' ||	c == '*')
		return (true);
	return(false);

}

static float doMath(int a, int b, int operation) {
	cout << "\nStarting doMath(" << a << ", " << b << ", " << operation << ")" << endl;
	float result = 0.0;

	switch(operation) {
		case 43:
			result = a + b;
			break;
		case 45:
			result = a - b;
			break;
		case 42:
			result = b * a;
			break;
		case 47:
			if (b != 0)
				result = static_cast<float>(a) / b;
			else
				result = std::numeric_limits<float>::infinity();
			break;
	}
	cout << "Leaving doMath(" <<  result << ")" << endl;
	return (result);
}

void	RPN::parseInput() {
	cout << "Starting parseInput()" << endl;
	string token;
	std::stringstream ss(_raw);

	while (std::getline(ss, token, ' ')){
		if (isOperator(token[0])) {
			if (token.length() == 1) {
				_cstk.push((token[0]));
				_opCount++;
			}
			else {
				cout << RED "Error: Invalid operator found (Available operators : + - / *)" NC << endl;
				exit(EXIT_FAILURE);
			}
		}
		else if (isOperand(token[0])) {
			if (token.length() == 1) {
				_cstk.push((token[0] - 48));
				_nbCount++;
			}
			else {
				cout << RED "Error: Invalid operand found (Limits: 0 - 9)" NC << endl;
				exit (EXIT_FAILURE);
			}
		}
		else {
			cout << RED "Error: Invalid character." NC << endl;
			exit (EXIT_FAILURE);
		}
	}
	if (((_opCount + _nbCount) % 2) == 0 || _nbCount < _opCount) { 
		cout << RED "Error: Invalid line" NC << endl;
		exit (EXIT_FAILURE);
	}
	cout << "Leaving parseInput()" << endl;
}

void	RPN::calculate() {
	int a, b, c, op = -1;
	stack<int> ret;

	while (_cstk.size()) {
		int tmp = _cstk.top();
		ret.push(tmp);
		_cstk.pop();
	}

	while (ret.size() > 1) {
		int tmp = ret.top();
		if (isOperator(tmp) == false) {
			a = ret.top();
			ret.pop();
			b = ret.top();
			ret.pop();
			
			if (isOperator(ret.top()) == false) {
				c = ret.top();
				ret.pop();
				op = ret.top();
				ret.pop();
				ret.push(doMath(b, c, op));
				ret.push(a);
			}
			else {	
				op = ret.top();
				ret.pop();
				ret.push(doMath(a, b, op));
			}
		}
		else {
			ret.push(ret.top());
		}
	// stack<int> stmp = ret;
	// for (int i = 0; stmp.size() > 0; i++) {
	// 	cout << i << " ret.top() = " << stmp.top() << endl;
	// 	stmp.pop();
	// }
	}
	cout << GRN << "\t" << ret.top() << NC << endl;
}



/*
   string::iterator it;
   for(it=postfix.begin(); it!=postfix.end(); it++){
      //read elements and perform postfix evaluation
      if(isOperator(*it) != -1){
         a = stk.top();
         stk.pop();
         b = stk.top();
         stk.pop();
         stk.push(operation(a, b, *it));
      }
      else if(isOperand(*it) > 0){
         stk.push(scanNum(*it));
      }
   }
   return stk.top();
}

*/