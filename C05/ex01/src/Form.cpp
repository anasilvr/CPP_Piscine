#include "../include/Form.hpp"

// Default constructor
Form::Form()
    : _formName("Unknown"),
      _isSigned(false),
      _gradeRestrict(1),
      _execRestrict(0) {
    cout << MAG "Form created.\t[DEFAULT]" NC << endl;
    return;
}

// Constructor
Form::Form(string name, int gradeR, int execR)
    : _formName(name), _gradeRestrict(gradeR), _execRestrict(execR) {
    _isSigned = false;
    if (gradeR < 1)
        throw(Form::GradeTooHighException());
    else if (gradeR > 150)
        throw(Form::GradeTooLowException());
    else {
        cout << MAG "Form [" << _formName;
        cout << "] of Grade/Exec restrictions of [" << _gradeRestrict;
        cout << "/" << _execRestrict << "] created." NC << endl;
    }
    return;
}

// Copy constructor
Form::Form(const Form& other)
    : _formName(other._formName),
      _gradeRestrict(other._gradeRestrict),
      _execRestrict(other._execRestrict) {
    *this = other;
    return;
}

// Copy assignment overload
Form& Form::operator=(const Form& rhs) {
    if (this != &rhs) _isSigned = rhs._isSigned;
    return *this;
}

// Default destructor
Form::~Form() {
    return;
}

const string Form::getName(void) const {
    return (_formName);
}
bool Form::getSignatureStatus(void) const {
    return (_isSigned);
}
int Form::getSignRestriction(void) const {
    return (_gradeRestrict);
}
int Form::getExecRestriction(void) const {
    return (_execRestrict);
}

void Form::beSigned(const Bureaucrat& b) {
    int grade = b.getGrade();

    if (grade > _gradeRestrict) {
        throw Bureaucrat::GradeTooLowException();
        return;
    }
    _isSigned = true;
    //	cout << MAG "Form [" << _formName << "] signed by [";
    //	cout << b.getName() << "]" << endl;
}

std::ostream& operator<<(std::ostream& out, Form const& arg) {
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