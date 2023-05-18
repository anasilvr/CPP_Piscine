
#include "../include/Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat() : _name("Unknown"), _grade(150) {
    cout << YEL "Bureaucrat " << _name;
    cout << " of grade " << _grade;
    cout << " created.\t[DEFAULT]" NC << endl;
    return;
}

Bureaucrat::Bureaucrat(string name, int grade) : _name(name), _grade(grade) {
    if (grade < 1)
        throw(Bureaucrat::GradeTooHighException());
    else if (grade > 150)
        throw(Bureaucrat::GradeTooLowException());
    else {
        cout << YEL "Bureaucrat [" << _name;
        cout << "] of grade [" << _grade;
        cout << "] created." NC << endl;
    }
    return;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name) {
    *this = other;
    cout << YEL "Bureaucrat [" << _name;
    cout << "] of grade [" << _grade;
    cout << "] created by copy." NC << endl;
    return;
}

// Copy assignment overload
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
    if (this != &rhs) _grade = rhs._grade;
    return *this;
}

// Default destructor
Bureaucrat::~Bureaucrat() {
    cout << YEL "Bureaucrat [" << _name;
    cout << "] destroyed." NC << endl;
    return;
}

string const Bureaucrat::getName(void) const {
    return (_name);
}

int Bureaucrat::getGrade(void) const {
    return (_grade);
}

void Bureaucrat::gradeUp(void) {
    if (_grade - 1 < 1)
        throw(Bureaucrat::GradeTooHighException());
    else {
        _grade--;
        cout << YEL "Bureaucrat [" << _name;
        cout << "] upgraded to [" << _grade;
        cout << "] \xF0\x9F\x94\xBA" NC << endl;
    }
}

void Bureaucrat::gradeDown(void) {
    if (_grade + 1 > 150)
        throw(Bureaucrat::GradeTooLowException());
    else {
        _grade++;
        cout << YEL "Bureaucrat [" << _name;
        cout << "] downgraded to [" << _grade;
        cout << "] \xF0\x9F\x94\xBB" NC << endl;
    }
}

void Bureaucrat::signForm(AForm &f) {
    try {
        f.beSigned(*this);
        cout << YEL "Bureaucrat [" << getName();
        cout << "] signed form [" << f.getName();
        cout << "] \xF0\x9F\x93\x9D" NC << endl;
    } catch (const std::exception &e) {
        std::cerr << YEL "Bureaucrat [" << getName();
        cout << "] "<< RED "couldn’t" NC << YEL " sign form [" << f.getName();
        cout << "] because [" << e.what() << "]" NC << endl;
    }
}

void Bureaucrat::executeForm(AForm const &form) {
	try {
		form.execute(*this);
		cout << YEL "Bureaucrat [" << getName() << "] executed form [";
		cout << form.getName() << "]" << NC << endl;
	}
	catch (std::exception &e) {
		std::cerr << RED "\xE2\x9D\x8C [Exec] Error: " << e.what() << NC << endl;
	}

}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &arg) {
    out << YEL << arg.getName();
    out << ", bureaucrat grade " << arg.getGrade();
    out << "." << NC << endl;
    return (out);
}

const char *Bureaucrat::GradeTooHighException::what () const throw () {
		return ("Grade Too High!");
}

const char *Bureaucrat::GradeTooLowException::what () const throw () {
		return ("Grade Too Low!");
}