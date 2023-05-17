#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

/*
TODO: 
---[x] FORM'S CHANGES
[x] the base class Form must be an abstract class. 
[x] the form’s attributes need to remain private.

---[x] BUREAUCRAT'S CHANGES
[x] add the executeForm(Form const & form) member function to the Bureaucrat.
It must attempt to execute the form. If it’s successful, print something like:
<bureaucrat> executed <form> If not, print an explicit error message.

---[x] NEW CONCRETE CLASSES
Add the following concrete classes:
[x] ShrubberyCreationForm: 
	[x] Required grades: sign 145, exec 137
	[x] Create a file <target>_shrubbery in the working directory, and writes ASCII trees inside it.

[x] RobotomyRequestForm: 
	[x] Required grades: sign 72, exec 45
	[x] Makes some drilling noises. Then, informs that <target> has been robotomized 
	successfully 50% of the time. Otherwise, informs that the robotomy failed.

[x] PresidentialPardonForm: 
	[x] Required grades: sign 25, exec 5
	[x] Informs that <target> has been pardoned by Zaphod Beeblebrox.

[x] add the execute(Bureaucrat const & executor) const member function to
the base form and implement a function to execute the form’s action on the concrete
classes.
	[] Check that the form is signed
	[] Check that the bureaucrat attempting to execute the form is high enough.
	Otherwise, throw an appropriate exception.

[] All of them take only one parameter in their constructor: the target of the form.
For example, "home" if you want to plant shrubbery at home.

*/

#define ERR_SIGN \
    (std::cerr << RED "\xE2\x9D\x8C [Sign] Error: " << e.what() << NC << endl)

#define ERR_EXEC \
    (std::cerr << RED "\xE2\x9D\x8C [Exec] Error: " << e.what() << NC << endl)

#define ERR_CTOR \
    (std::cerr << RED "\xE2\x9D\x8C [Ctor] Error: " << e.what() << NC << endl)

#define ERR_LIMITS \
    (std::cerr << RED "\xE2\x9D\x8C [Up/Downgrade] Error: " << e.what() << NC << endl)

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

    cout << WHTHB "\n\tEnding program." NC << endl;
}