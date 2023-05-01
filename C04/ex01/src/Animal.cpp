#include "../include/Animal.hpp"

Animal::Animal() : _type("undefined") {
	cout << RED << "\t[Default]\tAnimal of type [" << _type << "] created." << RESET << endl;
}
Animal::Animal(const string t) : _type(t) {
	cout << RED << "\t[Defined]\tAnimal of type [" << _type << "] created." << RESET << endl;
}

Animal::Animal(const Animal &other){
	*this = other;
	cout << RED << "\t[Copy]\tAnimal of type [" << _type << "] created." << RESET << endl;
}

Animal &Animal::operator=(const Animal &rhs){
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

Animal::~Animal() {
	cout << RED << "\tAnimal of type [" << _type << "] destroyed." << RESET << endl;
}

string	Animal::getType() const {
	return(_type);
}

void	Animal::setType(const string& t){
	_type = t;
}

void Animal::makeSound() const {
	cout << RED << "The [" << _type << "] animal is silent." << RESET << endl;
} 