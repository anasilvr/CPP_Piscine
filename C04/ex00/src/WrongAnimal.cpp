#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("undefined") {
	cout << BLU << "\t[Default]\tWrongAnimal of type [" << _type << "] created." << RESET << endl;
}
WrongAnimal::WrongAnimal(const string t) : _type(t) {
	cout << BLU << "\t[Defined]\tWrongAnimal of type [" << _type << "] created." << RESET << endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other){
	*this = other;
	cout << BLU << "\t[Copy]\tWrongAnimal of type [" << _type << "] created." << RESET << endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs){
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	cout << BLU << "\tWrongAnimal of type [" << _type << "] destroyed." << RESET << endl;
}

string	WrongAnimal::getType() const {
	return(_type);
}

void	WrongAnimal::setType(const string& t){
	_type = t;
}

void WrongAnimal::makeSound() const {
	cout << BLU << "The [" << _type << "] WrongAnimal is making weird noises. Stay away!" << RESET << endl;
} 