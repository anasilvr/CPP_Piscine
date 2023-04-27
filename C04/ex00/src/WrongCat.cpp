#include "../include/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	cout << MAG <<"\t[Default]\tWrongCat of type [" << _type << "] created." << RESET << endl;
}
WrongCat::WrongCat(const string t) : WrongAnimal(t) {
	cout << MAG <<"\t[Defined]]\tWrongCat of type [" << _type << "] created." << RESET << endl;
}

WrongCat::WrongCat(const WrongCat &other){
	*this = other;
	cout << MAG << "\t[Copy]\tWrongCat of type [" << _type << "] created." << RESET << endl;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs){
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

WrongCat::~WrongCat() {
	cout << MAG <<"\tWrongCat of type [" << _type << "] destroyed." << RESET << endl;
}

void WrongCat::makeSound() const {
	cout << MAG <<"The [" << _type << "] WrongCat burps." << RESET << endl;
} 