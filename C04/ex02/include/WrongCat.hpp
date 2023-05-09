#pragma once

#include "../include/WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(const string t);
	WrongCat(const WrongCat &other);
	WrongCat &operator=(const WrongCat &rhs);
	~WrongCat();

	void makeSound() const; 
};
