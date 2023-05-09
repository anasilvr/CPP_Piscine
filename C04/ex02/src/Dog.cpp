#include "../include/Dog.hpp"
#include "../include/Brain.hpp"

Dog::Dog() : AAnimal("dog"), _brain(new Brain()) {
	cout << YEL << "\t[Default]\tDog of type [" << _type << "] created." <<RESET << endl;
}
Dog::Dog(const string t) : AAnimal(t), _brain(new Brain()) {
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
	delete this->_brain;
	cout << YEL << "\tDog of type [" << _type << "] destroyed." <<RESET << endl;
}

void Dog::makeSound() const {
	cout << "The [" << _type << "] dog barks." << endl;
} 

Brain* Dog::getBrain(void) const {
	return(this->_brain);
}