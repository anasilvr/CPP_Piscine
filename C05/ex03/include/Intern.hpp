#pragma once

#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

// Class declaration
class Intern {
 public:
  Intern();
  ~Intern();

	AForm*	makeForm (string fName, string target);

	class FormNotFound : public std::exception {
		public:
			const char * what () const throw () {
				return ("Intern is panicking because he couldn't find this form.");
			}
	};
 
 private:
  Intern(const Intern &other);
  Intern &operator=(const Intern &rhs);
  
};

