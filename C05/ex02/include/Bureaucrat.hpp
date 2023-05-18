/*
---[] BUREAUCRAT'S CHANGES
[] add the executeForm(Form const & form) member function to the Bureaucrat.
It must attempt to execute the form. If it’s successful, print something like:
<bureaucrat> executed <form>
If not, print an explicit error message.
*/

#pragma once

#include <iostream>
#include "../include/colors.hpp"
#include "../include/AForm.hpp"

using std::cout;
using std::endl;
using std::string;

class AForm;

// Class declaration
class Bureaucrat {
 public:
  Bureaucrat(string name, int grade);
  Bureaucrat(const Bureaucrat &other);
  Bureaucrat &operator=(const Bureaucrat &rhs);
  ~Bureaucrat();

	string const getName (void) const;
	int		getGrade (void) const;
	void	gradeUp(void);
	void	gradeDown(void);

	void signForm(AForm &f);
	void executeForm(AForm const &form);

	class GradeTooHighException : public std::exception {
		public:
			const char * what () const throw ();
	};

	class GradeTooLowException : public std::exception {
		public:
			const char * what () const throw ();
	};

 private:
	Bureaucrat();
	string const _name;
	unsigned int _grade;
};

std::ostream& operator<<(std::ostream& out, Bureaucrat const& arg);