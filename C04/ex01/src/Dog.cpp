#include "../include/Dog.hpp"

Dog::Dog() : Animal("dog") {
	cout << YEL << "\t[Default]\tDog of type [" << _type << "] created." <<RESET << endl;
}
Dog::Dog(const string t) : Animal(t) {
	cout << YEL << "\t[Defined]\tDog of type [" << _type << "] created." << RESET << endl;
}

Dog::Dog(const Dog &other){
	*this = other;
	cout << YEL << "\t[Copy]\tAnimal of type [" << _type << "] created." << RESET << endl;
}

Dog &Dog::operator=(const Dog &rhs){
	if (this != &rhs)
		_type = rhs._type;
	return(*this);
}

Dog::~Dog() {
	cout << YEL << "\tDog of type [" << _type << "] destroyed." <<RESET << endl;
}

void Dog::makeSound() const {
	cout << "The [" << _type << "] dog barks." << endl;
} 