#include "../include/AMateria.hpp"
#include "../include/Character.hpp"
#include "../include/Ice.hpp"
#include "../include/MateriaSouce.hpp"

int main()
{
	cout << BYEL "\tMain says: Creating new MateriaSource." RESET << endl;
	IMateriaSource* src = new MateriaSource();
	cout << BYEL "\tMain says: Teaching a new materia of type ICE." RESET << endl;
	src->learnMateria(new Ice());
	// src->learnMateria(new Cure());
	cout << BYEL "\tMain says: Creating a new character." RESET << endl;
	ICharacter* me = new Character("me");
	cout << BYEL "\tMain says: Creating a new materia." RESET << endl;
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	cout << BYEL "\tMain says: Deleting everything." RESET << endl;
	// delete bob;
	// delete me;
	delete src;
	cout << BYEL "\tMain says: Bye la." RESET << endl;
 	return 0;
}
