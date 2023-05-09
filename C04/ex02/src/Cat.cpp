#include "../include/Cat.hpp"

Cat::Cat() : AAnimal("cat"), _brain(new Brain()) {
	cout << GRN <<"\t[Default]\tCat of type [" << _type << "] created." << RESET << endl;
}
Cat::Cat(const string t) : AAnimal(t), _brain (new Brain()) {
	cout << GRN <<"\t[Defined]]\tCat of type [" << _type << "] created." << RESET << endl;
}

Cat::Cat(const Cat &other): _brain (new Brain()){
	*this = other;
	cout << GRN << "\t[Copy]\t\tCat of type [" << _type << "] created." << RESET << endl;
}

Cat &Cat::operator=(const Cat &rhs){
	if (this != &rhs){
		_type = rhs._type;
		*_brain = *rhs._brain;
	}
	return (*this);
}

Cat::~Cat() {
	delete this->_brain;
	cout << GRN <<"\tCat of type [" << _type << "] destroyed." << RESET << endl;
}

void Cat::makeSound() const {
	cout << GRN <<"The [" << _type << "] cat meows." << RESET << endl;
} 

Brain* Cat::getBrain(void) const {
	return(this->_brain);
}