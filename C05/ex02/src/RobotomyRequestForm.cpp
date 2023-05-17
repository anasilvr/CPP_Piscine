
#include "../include/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
class AForm;

// Default constructor
//RobotomyRequestForm::RobotomyRequestForm() { return; }

RobotomyRequestForm::RobotomyRequestForm(string target) : AForm (target, 72, 45) { return; }

// // Copy constructor
// RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) {}
//     *this = other;
//     return;
// }

// // Copy assignment overload
// RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
// 	(void)rhs;
//   return *this;
// }

// Default destructor
RobotomyRequestForm::~RobotomyRequestForm() { return; }

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	if (getSignatureStatus() == false) {
		throw AForm::NotSigned();
		return;
	}
	if (executor.getGrade() > getExecRestriction()) {
		throw AForm::GradeTooLowException();
		return;
	}
	srand(time(NULL));
	int exec = rand();
	if (exec % 2) {
		system ("afplay drill.mp3 &>/dev/null &");
		cout << GRN << "[" << getName() <<"] has been robotomized." << endl;
	}
	else {
		cout << GRN << "[" << getName() <<"] robotomy";
		cout << RED " failed" << NC << "." << endl;
	}
}