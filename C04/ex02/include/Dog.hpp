#pragma once

#include "../include/Animal.hpp"

class Dog : public AAnimal
{
private:
	Brain *_brain;
public:
	Dog();
	Dog(const string t);
	Dog(const Dog &other);
	Dog &operator=(const Dog &rhs);
	~Dog();

	void makeSound() const; 
	Brain* getBrain(void) const;
};
