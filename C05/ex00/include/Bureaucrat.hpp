#pragma once

#include <iostream>
#include "../include/colors.hpp"

using std::cout;
using std::endl;
using std::string;

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

	class GradeTooHighException : public std::exception {
		public:
			const char * what () const throw () {
				return ("Grade Too High!");
			}
	};

	class GradeTooLowException : public std::exception {
		public:
			const char * what () const throw () {
				return ("Grade Too Low!");
			}
	};

 private:
	Bureaucrat();
	string const _name;
	unsigned int _grade;
};

std::ostream& operator<<(std::ostream& out, Bureaucrat const& arg);