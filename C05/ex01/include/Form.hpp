#pragma once

#include "../include/Bureaucrat.hpp"

using std::cout;
using std::endl;
using std::string;
class Bureaucrat;

// Class declaration
class Form {
 public:
	Form(string name, int gradeR, int execR);
  	~Form();

	const string getName (void) const;
	bool		getSignatureStatus (void) const;
	int	getSignRestriction (void) const;
	int	getExecRestriction (void) const;

	void	beSigned(const Bureaucrat& b);

	class GradeTooHighException : public std::exception {
		public:
			const char * what () const throw ();
	};

	class GradeTooLowException : public std::exception {
		public:
			const char * what () const throw ();
	};

 private:
	Form();
	  Form(const Form &other);
 	 Form &operator=(const Form &rhs);
	string const _formName;
	
	bool	_isSigned;
	int	const _gradeRestrict;
	int const _execRestrict;
  
};

std::ostream& operator<<(std::ostream& out, Form const& arg);
