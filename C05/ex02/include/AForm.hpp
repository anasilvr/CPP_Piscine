#pragma once

#include "../include/Bureaucrat.hpp"

using std::cout;
using std::endl;
using std::string;

class Bureaucrat;

// Class declaration
class AForm {
   public:
    AForm(string name, int gradeR, int execR);
    virtual ~AForm();

    const string getName(void) const;
    bool         getSignatureStatus(void) const;
    int          getSignRestriction(void) const;
    int          getExecRestriction(void) const;

    void         beSigned(const Bureaucrat& b);
    virtual void execute(Bureaucrat const& executor) const = 0;

	class GradeTooHighException : public std::exception {
		public:
			const char * what () const throw ();
	};

	class GradeTooLowException : public std::exception {
		public:
			const char * what () const throw ();
	};

	class NotSigned : public std::exception {
		public:
			const char * what () const throw ();
	};

	// class AlreadySigned : public std::exception {
    //    public:
    //     const char* what() const throw() {
    //         return ("Form already signed.");
    //     }
    // };

   private:
    AForm();
    AForm(const AForm& other);
    AForm&       operator=(const AForm& rhs);
    string const _formName;

    bool      _isSigned;
    int const _gradeRestrict;
    int const _execRestrict;
};

std::ostream& operator<<(std::ostream& out, AForm const& arg);
