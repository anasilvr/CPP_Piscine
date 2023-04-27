#pragma once

#include "../include/Animal.hpp"
#include <iostream>

class Dog : public Animal
{
private:

public:
	Dog();
	Dog(const string t);
	Dog(const Dog &other);
	Dog &operator=(const Dog &rhs);
	~Dog();

	void makeSound() const; 
};
