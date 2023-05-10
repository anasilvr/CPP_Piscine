
#include "../include/Ice.hpp"

// Default constructor
Ice::Ice() : AMateria("ice") {
	cout << BLU "Ice created." RESET << endl;
	return;
}

// Copy constructor
Ice::Ice(const Ice &other) : AMateria(other) {
	*this = other;
	cout << BLU "Ice created by copy. ( " RESET << endl;
	return;
}

// Copy assignment overload
Ice &Ice::operator=(const Ice &rhs) {
	if (this != &rhs) {
		_type = rhs._type;
	}
	return *this;
}

// Default destructor
Ice::~Ice() { 
	cout << BLU "Ice destroyed." RESET << endl;
}


AMateria* Ice::clone(void) const {
	return (new Ice);
}

void Ice::use (ICharacter & target) {
	cout << BLU "* shoots an ice bolt at " << target.getName()<< " *" RESET << endl;
}