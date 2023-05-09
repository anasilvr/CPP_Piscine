#include <iostream>
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongCat.hpp"

#define REDHB "\e[0;101m"

int main ()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	cout << endl;
	delete j;//should not create a leak
	delete i;

	cout << REDHB << "\n#_____PDF BASIC TEST____#" << RESET << endl;
	cout << "\nCreating an array of 10 animals...\n";
	Animal *pdf[10];

	cout << "\nAssigning cats and dogs:\n";
	for (int i = 0; i < 10; i++)
	{
		if (i < 5){
			cout << BRED << i + 1;
			pdf[i] = new Cat();
		}
		else{
			cout << BRED << i + 1;
			pdf[i] = new Dog();
		}
	}

	cout << "\nDestroying cats and dogs:\n";
	for (int i = 0; i < 10; i++){
		delete pdf[i];
		cout << endl;
	}

	cout << REDHB << "\n#_____DEEP COPY TEST____#" << RESET << endl;;
	Cat minou1;
	cout << endl;

	Cat minou2(minou1);
	cout << endl;

	Cat minou3 = minou2;
	cout << endl;

	cout <<"\tBrain address check.\n";
	cout << "\tMinou 1: " << minou1.getBrain() << endl;
	cout << "\tMinou 2: " << minou2.getBrain() << endl;
	cout << "\tMinou 3: " << minou3.getBrain() << endl;

// create ideas and change content around to make sure every brain is isolated

	cout << REDHB << "\n#_____EVAL TEST____#" << RESET << endl;
	Cat basic;
	{
		Cat tmp = basic;
	}

 	cout << REDHB << "\n#_____END____#" << RESET << endl;
	return (0);
}