#include "../include/AMateria.hpp"
#include "../include/Character.hpp"
#include "../include/Cure.hpp"
#include "../include/Ice.hpp"
#include "../include/MateriaSouce.hpp"
int main()
{
	cout << BYEL "\t[Main] Creating new MateriaSource." RESET << endl;
	IMateriaSource* src = new MateriaSource();

	cout << BYEL "\t[Main] Learning a new materias." RESET << endl;
	for (int i = 0; i < 10; i++) {
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
	}
	cout << BYEL "\t[Main] Creating a new character." RESET << endl;
	ICharacter* me = new Character("me");

	cout << BYEL "\t[Main] Creating and equipping new materias." RESET << endl;
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->unequip(0);
	Character* bob = new Character("bob");
	cout << BYEL "\t[Main] Attacking Bob." RESET << endl;
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	// me->use(0, *bob);
	// me->use(1, *bob);
	// me->use(3, *bob);
	// me->use(2, *bob);
	// me->use(4, *bob); // invalid index should throw an error
	//cout << BYEL "\t[Main] Testing copy constructor." RESET << endl;
	// Character *yan (new Character (*bob));
	// cout << "[" << bob <<"] coucou " << bob->getName() << endl;
	// cout << "[" << yan <<"] coucou " << yan->getName() << endl;
	cout << BYEL "\t[Main] Deleting everything." RESET << endl;
	delete bob;
	delete me;
	delete src;
	cout << BYEL "\t[Main] Bye la." RESET << endl;
 	return 0;
}
