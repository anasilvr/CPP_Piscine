#include "../include/RPN.hpp"

RPN::RPN (const char *av) : _raw(av), _opCount(0), _nbCount(0) {
	verifyInputContent();
	verifyInputFormat();
	calculate();
	cout << "Result: " << _cstk.top() << NC << endl;
}

RPN::~RPN() {}

void RPN::verifyInputContent() {
	const char *validChar = "0123456789+-/* ";
	_iLen = _raw.length();
	bool isValid;

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

static float doMath(float a, float b, char operation) {
//	cout << "\nStarting doMath(" << a << ", " << b << ", " << operation << ")" << endl;
	float result = 0.0;

	switch(operation) {
		case '+':
			result = b + a;
			break;
		case '-':
			result = b - a;
			break;
		case '*':
			result = b * a;
			break;
		case '/':
			if (a != 0)
				result = static_cast<float>(b) / a;
			else
				result = std::numeric_limits<float>::infinity();
			break;
		default:
			cout << RED "Error." NC << endl;
			exit(EXIT_FAILURE);
	}
	return (result);
}

void	RPN::verifyInputFormat() {
	string token;
	std::stringstream ss(_raw);

	while (std::getline(ss, token, ' ')){
		if (isOperator(token[0])) {
			if (token.length() == 1)
				_opCount++;
			else if (std::stoi(token)) {
				cout << RED "Error: Invalid operand found (Limits: 0 - 9)" NC << endl;
				exit (EXIT_FAILURE);
			}
			else {
				cout << RED "Error: Invalid operator found (Available operators : + - / *)" NC << endl;
				exit(EXIT_FAILURE);
			}
		}
		else if (isOperand(token[0])) {
			if (token.length() == 1)
				_nbCount++;
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
	if (((_opCount + _nbCount) % 2) == 0 || _nbCount < _opCount || _opCount == 0) { 
		cout << RED "Error: Invalid line" NC << endl;
		exit (EXIT_FAILURE);
	}
}

static float parseNb(char c) {
	int value;
	value = c - 48;
	return (static_cast<float>(value));
}

void RPN::calculate() {

	float a, b = 0;
	string::iterator it;

	for (it = _raw.begin(); it != _raw.end(); it++) {
		if (isOperator(*it) == true) {
			if (_cstk.empty()) {
				cout << RED "Error: Invalid line" NC << endl;
				exit (EXIT_FAILURE);
			}
			a = _cstk.top();
			_cstk.pop();
			if (_cstk.empty()) {
				cout << RED "Error: Invalid line" NC << endl;
				exit (EXIT_FAILURE);
			}
			b = _cstk.top();
			_cstk.pop();
			_cstk.push(doMath(a, b, *it));
		}
		else if (isOperand(*it) == true)
			_cstk.push(parseNb(*it));
	}
}