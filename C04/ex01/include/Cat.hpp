#pragma once

#include "../include/Animal.hpp"
#include <iostream>

class Cat : public Animal
{
private:

public:
	Cat();
	Cat(const string t);
	Cat(const Cat &other);
	Cat &operator=(const Cat &rhs);
	~Cat();

	void makeSound() const; 
};
