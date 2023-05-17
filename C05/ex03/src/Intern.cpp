#include "../include/Intern.hpp"

// Default constructor
Intern::Intern() {
	cout << CYN "Intern created." NC << endl;
	return;
}

// // Copy constructor
// Intern::Intern(const Intern &other) {
//   *this = other;
//   return;
// }

// // Copy assignment overload
// Intern &Intern::operator=(const Intern &rhs) {
//   (void)rhs;
//   return *this;
// }

// Default destructor
Intern::~Intern() {
	cout << CYN "Intern destroyed." NC << endl;
	return;
}

AForm*	Intern::makeForm (string formName, string target) {
	string forms[3] = {"shruberry", "robotomy", "pardon" };
	int	option = -1;
	for (int i = 0; i < 3; i++) {
		if (!forms[i].compare(formName))
			option = i;
	}
	switch (option) {
		case 0:
			return (new ShrubberyCreationForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new PresidentialPardonForm(target));
		default:
			throw Intern::FormNotFound();
	}
}