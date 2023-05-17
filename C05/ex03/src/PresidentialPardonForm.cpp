
#include "../include/PresidentialPardonForm.hpp"
class AForm;

// Default constructor
//PresidentialPardonForm::PresidentialPardonForm() { return; }

PresidentialPardonForm::PresidentialPardonForm(string target) : AForm (target, 25, 5) { return; }

// // Copy constructor
// PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) {}
//     *this = other;
//     return;
// }

// // Copy assignment overload
// PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
// 	(void)rhs;
//   return *this;
// }

// Default destructor
PresidentialPardonForm::~PresidentialPardonForm() { return; }

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
	if (getSignatureStatus() == false) {
		throw AForm::NotSigned();
		return;
	}
	if (executor.getGrade() > getExecRestriction()) {
		throw AForm::GradeTooLowException();
		return;
	}
	cout << GRN << "[" << getName() <<"] has been pardoned by Zaphod Beeblebrox.";
	cout << NC << endl;
}