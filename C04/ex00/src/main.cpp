#include <iostream>
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongCat.hpp"

#define REDHB "\e[0;101m"

int main ()
{
	const Animal* void_animal = new Animal();
	cout << endl;
	const Animal* typed_animal = new Animal("random");
	cout << endl;
	const Animal* void_dog = new Dog();
	cout << endl;
	const Animal* typed_dog = new Dog("black");
	cout << endl;
	const Animal* void_cat = new Cat();
	cout << endl;
	const Animal* typed_cat = new Cat("white");
	cout << endl;
	const WrongAnimal* void_wronganimal = new WrongCat();
	cout << endl;
	const WrongAnimal* typed_wronganimal = new WrongCat("bird");
	cout << endl;
	const WrongCat* void_wrongcat = new WrongCat();
	cout << endl;
	const WrongCat* typed_wrongcat = new WrongCat("fish");

	// cout << endl;
	// cout << REDHB << "Created animals and its types:" << RESET << endl;
	// cout << "Default animal's type: "<< void_animal->getType() << endl;
	// cout << "Default animal's type: "<< typed_animal->getType() << endl;
	// cout << "Default dog's type: "<< void_dog->getType() << endl;
	// cout << "Specified dog's type: "<< typed_dog->getType() << endl;
	// cout << "Default cat's type: "<< void_cat->getType() << endl;
	// cout << "Specified cat's type: "<< typed_cat->getType() << endl;
	// cout << "Default wrong animal's type: "<< void_wronganimal->getType() << endl;
	// cout << "Specified wrong animal's type: "<< typed_wronganimal->getType() << endl;
	// cout << "Default wrong cat's type: "<< void_wrongcat->getType() << endl;
	// cout << "Specified wrong cat's type: "<< typed_wrongcat->getType() << endl;
	
	cout << endl;
	cout << REDHB << "Animals start making sounds..." << RESET << endl;
	void_animal->makeSound();
	typed_animal->makeSound(); 
	void_dog->makeSound();
	typed_dog->makeSound(); 
	void_cat->makeSound();
	typed_cat->makeSound(); 
	void_wronganimal->makeSound();
	typed_wronganimal->makeSound(); 
	void_wrongcat->makeSound();
	typed_wrongcat->makeSound(); 
	
	cout << endl;
	cout << REDHB << "Deleting animals..." << RESET << endl;
	delete void_animal;
	cout << endl;
	delete typed_animal;
	cout << endl;
	delete void_dog;
	cout << endl;
	delete typed_dog;
	cout << endl;
	delete void_cat;
	cout << endl;
	delete typed_cat;
	cout << endl;
	delete void_wronganimal;
	cout << endl;
	delete typed_wronganimal;
	cout << endl;
	delete void_wrongcat;
	cout << endl;
	delete typed_wrongcat;
	cout << endl;
	
 	cout << REDHB << "\n#_____LEAKS REPORT____#" << RESET << endl;
	return (0);
}