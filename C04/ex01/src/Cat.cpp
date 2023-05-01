#include "../include/Cat.hpp"

Cat::Cat() : Animal("cat") {
	cout << GRN <<"\t[Default]\tCat of type [" << _type << "] created." << RESET << endl;
}
Cat::Cat(const string t) : Animal(t) {
	cout << GRN <<"\t[Defined]]\tCat of type [" << _type << "] created." << RESET << endl;
}

Cat::Cat(const Cat &other){
	*this = other;
	cout <<GRN << "\t[Copy]\tCat of type [" << _type << "] created." << RESET << endl;
}

Cat &Cat::operator=(const Cat &rhs){
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

Cat::~Cat() {
	cout << GRN <<"\tCat of type [" << _type << "] destroyed." << RESET << endl;
}

void Cat::makeSound() const {
	cout << GRN <<"The [" << _type << "] cat meows." << RESET << endl;
} 