
#include "../include/Cure.hpp"

// Default constructor
Cure::Cure() : AMateria("cure") {
	cout << GRN "Cure created." RESET << endl;
	return;
}

// Copy constructor
Cure::Cure(const Cure &other) : AMateria(other) {
	*this = other;
	cout << GRN "Cure created by copy. ( " RESET << endl;
	return;
}

// Copy assignment overload
Cure &Cure::operator=(const Cure &rhs) {
	if (this != &rhs) {
		_type = rhs._type;
	}
	return *this;
}

// Default destructor
Cure::~Cure() { 
	cout << GRN "Cure destroyed." RESET << endl;
}


AMateria* Cure::clone(void) const {
	return (new Cure);
}

void Cure::use (ICharacter & target) {
	cout << GRN "* heals " << target.getName()<< "'s wounds *" RESET << endl;
}