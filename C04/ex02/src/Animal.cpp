#include "../include/Animal.hpp"

AAnimal::AAnimal() : _type("undefined") {
	cout << RED << "\t[Default]\tAnimal of type [" << _type << "] created." << RESET << endl;
}

AAnimal::AAnimal(const string t) : _type(t) {
	cout << RED << "\t[Defined]\tAnimal of type [" << _type << "] created." << RESET << endl;
}

AAnimal::AAnimal(const AAnimal &other){
	*this = other;
	cout << RED << "\t[Copy]\tAnimal of type [" << _type << "] created." << RESET << endl;
}

AAnimal &AAnimal::operator=(const AAnimal &rhs){
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

AAnimal::~AAnimal() {
	cout << RED << "\tAnimal of type [" << _type << "] destroyed." << RESET << endl;
}

string	AAnimal::getType() const {
	return(_type);
}

void	AAnimal::setType(const string& t){
	_type = t;
}

void AAnimal::makeSound() const {
	cout << RED << "The [" << _type << "] animal is silent." << RESET << endl;
} 