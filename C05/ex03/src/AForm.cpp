#include "../include/AForm.hpp"

// Default constructor
AForm::AForm()
    : _formName("Unknown"),
      _isSigned(false),
      _gradeRestrict(1),
      _execRestrict(0) {
    cout << MAG "Form created.\t[DEFAULT]" NC << endl;
    return;
}

// Constructor
AForm::AForm(string name, int gradeR, int execR)
    : _formName(name), _gradeRestrict(gradeR), _execRestrict(execR) {
    _isSigned = false;
    if (gradeR < 1)
        throw(AForm::GradeTooHighException());
    else if (gradeR > 150)
        throw(AForm::GradeTooLowException());
    else {
        cout << MAG "Form [" << _formName;
        cout << "] of Grade/Exec restrictions of [" << _gradeRestrict;
        cout << "/" << _execRestrict << "] created." NC << endl;
    }
    return;
}

// Copy constructor
AForm::AForm(const AForm& other)
    : _formName(other._formName),
      _gradeRestrict(other._gradeRestrict),
      _execRestrict(other._execRestrict) {
    *this = other;
    return;
}

// Copy assignment overload
AForm& AForm::operator=(const AForm& rhs) {
    if (this != &rhs)
		_isSigned = rhs._isSigned;
    return *this;
}

// Default destructor
AForm::~AForm() {
    return;
}

const string AForm::getName(void) const {
    return (_formName);
}
bool AForm::getSignatureStatus(void) const {
    return (_isSigned);
}
int AForm::getSignRestriction(void) const {
    return (_gradeRestrict);
}
int AForm::getExecRestriction(void) const {
    return (_execRestrict);
}

void AForm::beSigned(const Bureaucrat& b) {
    int grade = b.getGrade();

    if (grade > _gradeRestrict) {
        throw Bureaucrat::GradeTooLowException();
        return;
    }
    _isSigned = true;
    //	cout << MAG "Form [" << _formName << "] signed by [";
    //	cout << b.getName() << "]" << endl;
}

std::ostream& operator<<(std::ostream& out, AForm const& arg) {
    out << MAG << "Form Name: " << arg.getName();
    out << "\nSigned: ";
    if (arg.getSignatureStatus() == 1)
        out << "yes";
    else
        out << "no";
    out << "\nGrade Restriction: " << arg.getSignRestriction();
    out << "\nExec Restriction: " << arg.getExecRestriction();
    out << NC "\n" << endl;
    return (out);
}