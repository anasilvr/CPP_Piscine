
#include "../include/AMateria.hpp"

AMateria::AMateria(std::string const &type){
	_type = type;
	cout << "AMateria created with type: " << type << endl;
	return;
}

// Copy constructor
AMateria::AMateria(const AMateria &other) {
	*this = other;
	cout << "AMateria created by copy. ( ";
	cout << other._type << " = " << _type << " )" << endl;
	return;
}

// Copy assignment overload
AMateria &AMateria::operator=(const AMateria &rhs) {
	if (this != &rhs)
		_type = rhs._type;
	return *this;
}

// Default destructor
AMateria::~AMateria() {
	cout << "AMateria " << _type << " destroyed." << endl;
	return;
}


std::string const & AMateria::getType() const { return (_type); }

void AMateria::use(ICharacter& target){ (void)target; }