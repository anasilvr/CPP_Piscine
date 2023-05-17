#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Intern.hpp"

/*
TODO:
[] implement the Intern class. 
	[] No name, no grade, no unique characteristics. The only
	thing the bureaucrats care about is that they do their job.

[] makeForm() function.
	[] It takes two strings: formName and its target
	[] It return a pointer to a Form object (whose name is the one passed as parameter)
whose target will be initialized to the second parameter.
	[] Prints something like: Intern creates <form>
	[] If the form name passed as parameter doesn’t exist, print an explicit error message.

[] No if/elseif/else forest.

*/

#define ERR_SIGN \
    (std::cerr << RED "\xE2\x9D\x8C [Sign] Error: " << e.what() << NC << endl)

#define ERR_EXEC \
    (std::cerr << RED "\xE2\x9D\x8C [Exec] Error: " << e.what() << NC << endl)

#define ERR_CTOR \
    (std::cerr << RED "\xE2\x9D\x8C [Ctor] Error: " << e.what() << NC << endl)

#define ERR_LIMITS \
    (std::cerr << RED "\xE2\x9D\x8C [Up/Downgrade] Error: " << e.what() << NC << endl)

#define ERR_INTERN \
    (std::cerr << RED "\xE2\x9D\x8C [Intern] Error: " << e.what() << NC << endl)

int main(void) {
    cout << WHTHB
        "\n\tCreating bureaucrats (Two defaults, one by copy) and printing "
        "their details." NC
         << endl;
    Bureaucrat Val("Val", 1);
    Bureaucrat Ana("Ana", 145);
    Bureaucrat Yan("Yan", 26);
    cout << Val;
    cout << Yan;
    cout << Ana;

    cout << WHTHB "\n\tTrying to create bureaucrats with invalid grades." NC
         << endl;
    try {
        Bureaucrat Yuki("Yuki", 0);
        cout << Yuki;
    } catch (std::exception &e) {
        ERR_CTOR;
    }

    try {
        Bureaucrat Caca("Ana", -1);
        cout << Caca;
    } catch (std::exception &e) {
        ERR_CTOR;
    }

    try {
        Bureaucrat Duck("Duck", 151);
        cout << Duck;
    } catch (std::exception &e) {
        ERR_CTOR;
    }

    cout << WHTHB
        "\n\tTrying to gradeDown and gradeUp (exceding limits on gradeUp)" NC
         << endl;
    try {
        for (int i = 0; i < 10; i++) Val.gradeDown();
        for (int i = 0; i < 11; i++) Val.gradeUp();
    } catch (std::exception &e) {
        ERR_LIMITS;
    }

    cout << WHTHB
        "\n\tTrying to gradeDown and gradeUp (exceding limits on gradeDown)" NC
         << endl;
    try {
        for (int i = 0; i < 11; i++) Ana.gradeDown();
        for (int i = 0; i < 10; i++) Ana.gradeUp();
    } catch (std::exception &e) {
        ERR_LIMITS;
    }

    cout << WHTHB "\n\tPrinting ending values for each bureaucrat." NC << endl;
    cout << Val;
    cout << Yan;
    cout << Ana;

    cout << WHTHB "\n\tCreating ShrubberyCreationForm and trying to sign them." NC << endl;
    ShrubberyCreationForm t1 ("Erik");
    ShrubberyCreationForm t2 ("Morgan");
    ShrubberyCreationForm t3 ("JB");
    Val.signForm(t1);
    Ana.signForm(t2);
    Yan.signForm(t3);
    cout << endl;

	cout << WHTHB "\n\tTrying to execute ShrubberyCreationForm." NC << endl;
	try { Val.executeForm(t1); }
	catch (std::exception &e) { ERR_EXEC; }
	try { Ana.executeForm(t2); }
	catch (std::exception &e) { ERR_EXEC; }
	try { Yan.executeForm(t3); }
	catch (std::exception &e) { ERR_EXEC; }

    cout << WHTHB "\n\tCreating RobotomyRequestForm and trying to sign them." NC << endl;
    RobotomyRequestForm t4 ("Erik");
    RobotomyRequestForm t5 ("Morgan");
    RobotomyRequestForm t6 ("JB");
    Val.signForm(t4);
    Ana.signForm(t5);
    Yan.signForm(t6);
    cout << endl;

	cout << WHTHB "\n\tTrying to execute RobotomyRequestForm." NC << endl;
	try { Val.executeForm(t4); }
	catch (std::exception &e) { ERR_EXEC; }
	try { Ana.executeForm(t5); }
	catch (std::exception &e) { ERR_EXEC; }
	try { Yan.executeForm(t6); }
	catch (std::exception &e) { ERR_EXEC; }

    cout << WHTHB "\n\tCreating PresidentialPardonForms and trying to sign them." NC << endl;
    PresidentialPardonForm t7 ("Erik");
    PresidentialPardonForm t8 ("Morgan");
    PresidentialPardonForm t9 ("JB");
    Val.signForm(t7);
    Ana.signForm(t8);
    Yan.signForm(t9);
    cout << endl;

	cout << WHTHB "\n\tTrying to execute PresidentialPardonForms." NC << endl;
	try { Val.executeForm(t7); }
	catch (std::exception &e) { ERR_EXEC; }
	try { Ana.executeForm(t8); }
	catch (std::exception &e) { ERR_EXEC; }
	try { Yan.executeForm(t9); }
	catch (std::exception &e) { ERR_EXEC; }

    cout << WHTHB "\n\tPrinting forms' information." NC << endl;
    cout << endl;
	cout << "ShrubberyCreationForms [145/137]" << endl;
    cout << t1;
    cout << t2;
    cout << t3;
	cout << "RobotomyRequestForms [72/45]"<< endl;
    cout << t4;
    cout << t5;
    cout << t6;
	cout << "PresidentialPardonForms [25/5]" << endl;
    cout << t7;
    cout << t8;
    cout << t9;

	cout << WHTHB "\n\tCreating interns and giving them jobs." NC << endl;
	try {
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		delete rrf;
	}
	catch (std::exception &e) {
		ERR_INTERN;
	}

	cout << endl;
	try {
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy", "Homer");
		delete rrf;
	}
	catch (std::exception &e) {
		ERR_INTERN;
	}

	cout << endl;
	try {
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("pardon", "Marge");
		delete rrf;
	}
	catch (std::exception &e) {
		ERR_INTERN;
	}

	cout << endl;
	try {
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("shruberry", "Bart");
		delete rrf;
	}
	catch (std::exception &e) {
		ERR_INTERN;
	}

    cout << WHTHB "\n\tEnding program." NC << endl;
}