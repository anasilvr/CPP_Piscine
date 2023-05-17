
#include "../include/ShrubberyCreationForm.hpp"
class AForm;

// Default constructor
//ShrubberyCreationForm::ShrubberyCreationForm() { return; }

ShrubberyCreationForm::ShrubberyCreationForm(string target) : AForm (target, 145, 137) { return; }

// // Copy constructor
// ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) {}
//     *this = other;
//     return;
// }

// // Copy assignment overload
// ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
// 	(void)rhs;
//   return *this;
// }

// Default destructor
ShrubberyCreationForm::~ShrubberyCreationForm() { return; }

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	if (getSignatureStatus() == false) {
		throw AForm::NotSigned();
		return;
	}
	if (executor.getGrade() > getExecRestriction()) {
		throw AForm::GradeTooLowException();
		return;
	}
	string name = getName();
	std::ofstream ofile(name.append("_shrubbery"));
	if (ofile.good()) {
		ofile << "cpp/" << endl;
		ofile << "|- where/" << endl;
		ofile << "|- friends/" << endl;
		ofile << "|  |- have" << endl;
		ofile << "|  |- access" << endl;
		ofile << "|  |- to" << endl;
		ofile << "|- your/" << endl;
		ofile << "|  |- private" << endl;
		ofile << "|  |- members" << endl;
	}
}