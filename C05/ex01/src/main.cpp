#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

/*
TODO: Make a Form class. It has:
[x] *** A constant name.
[x] A boolean indicating whether it is signed (at construction, it’s not).
[x] *** A constant grade required to sign it.
[x] *** And a constant grade required to execute it.
All these attributes are private, not protected.

[x] The grades of the Form follow the same rules that apply to the Bureaucrat.

[x] Form getters
        - getName
        - getSignatureStatus
        - getSignRestriction
        - getExecRestriction

[x] beSigned() member function to the Form that takes a Bureaucrat as
parameter. It changes the form status to signed if the bureaucrat’s grade is
high enough (higher or egal to the required one).

[x] signForm() member function to the Bureaucrat. If the form got signed,
it will print something like: <bureaucrat> signed <form>
Otherwise, it will print something like: <bureaucrat> couldn’t sign <form>
because <reason>.

[x] overload of the insertion («) operator that prints all the form’s
informations
*/

#define ERR_MSG \
    (std::cerr << RED "\xE2\x9D\x8C Error: " << e.what() << NC << endl)

int main(void) {
    cout << WHTHB
        "\n\tCreating bureaucrats (Two defaults, one by copy) and printing "
        "their details." NC
         << endl;
    Bureaucrat Val("Val", 1);
    Bureaucrat Ana("Ana", 140);
    Bureaucrat Yan(Val);
    cout << Val;
    cout << Yan;
    cout << Ana;

    cout << WHTHB "\n\tTrying to create bureaucrats with invalid grades." NC
         << endl;
    try {
        Bureaucrat Yuki("Yuki", 0);
        cout << Yuki;
    } catch (std::exception &e) {
        ERR_MSG;
    }

    try {
        Bureaucrat Caca("Ana", -1);
        cout << Caca;
    } catch (std::exception &e) {
        ERR_MSG;
    }

    try {
        Bureaucrat Duck("Duck", 151);
        cout << Duck;
    } catch (std::exception &e) {
        ERR_MSG;
    }

    cout << WHTHB
        "\n\tTrying to gradeDown and gradeUp (exceding limits on gradeUp)" NC
         << endl;
    try {
        for (int i = 0; i < 10; i++) Val.gradeDown();
        for (int i = 0; i < 11; i++) Val.gradeUp();
    } catch (std::exception &e) {
        ERR_MSG;
    }

    cout << WHTHB
        "\n\tTrying to gradeDown and gradeUp (exceding limits on gradeDown)" NC
         << endl;
    try {
        for (int i = 0; i < 11; i++) Ana.gradeDown();
        for (int i = 0; i < 10; i++) Ana.gradeUp();
    } catch (std::exception &e) {
        ERR_MSG;
    }

    cout << WHTHB "\n\tPrinting ending values for each bureaucrat." NC << endl;
    cout << Val;
    cout << Yan;
    cout << Ana;

    cout << WHTHB "\n\tCreating forms and trying to sign them." NC << endl;
    Form easy("EasyForm", 150, 150);
    Form medium("MediumForm", 75, 75);
    Form hard("HardForm", 1, 1);
    Ana.signForm(easy);
    Ana.signForm(medium);
    Ana.signForm(hard);
    cout << endl;

    Val.gradeDown();
    Val.signForm(easy);
    Val.signForm(medium);
    Val.signForm(hard);

    cout << WHTHB "\n\tPrinting forms' information." NC << endl;
    cout << endl;
    cout << easy;
    cout << medium;
    cout << hard;

    cout << WHTHB "\n\tEnding program." NC << endl;
}