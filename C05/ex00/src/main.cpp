#include "../include/Bureaucrat.hpp"

/*
TODO: Un Bureaucrat doit avoir :
[x] Un name (nom) constant
[x] Un grade (échelon) pouvant aller de 1 (échelon le plus élevé) à 150 (échelon le plus bas).

[x] getName() 
[x] getGrade()

Toute tentative d’instancier un Bureaucrat en utilisant un échelon invalide jettera une
exception :
[x] Bureaucrat::GradeTooHighException
[x] Bureaucrat::GradeTooLowException

[x] Les exceptions jetées devront pouvoir être attrapées grâce à des blocs try and catch 

[x] Surcharge de l’opérateur d’insertion («) afin d’afficher: 
	"<name>, bureaucrat grade <grade>"
*/

int main (void)
{
	cout << BRED "\tCreating bureaucrats (One default, one by copy) and printing their details." NC << endl;
	Bureaucrat Val("Val", 1);
	Bureaucrat Yan (Val);
	cout << Val;
	cout << Yan << endl;

	cout << BRED "\tTrying to create bureaucrats with invalid grade." NC << endl;
	try {
		Bureaucrat Yuki ("Yuki", 0);
		Bureaucrat Ana ("Ana", -1);
		Bureaucrat Duck ("Duck", 151);
		cout << Yuki;
		cout << Ana;
		cout << Duck << endl;
	}
	catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << NC << endl;
	}
cout << BRED "\tTrying to gradeDown and gradeUp (exceding limits on gradeUp)" NC << endl;
	 try {
		for (int i = 0; i < 10; i++)
	 		Val.gradeDown();
		for (int i = 0; i < 11; i++)
	 		Val.gradeUp();
	}
	catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << NC << endl;
	}
}