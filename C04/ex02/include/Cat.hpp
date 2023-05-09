#pragma once

#include "../include/Animal.hpp"

class Cat : public AAnimal
{
private:
	Brain *_brain;
public:
	Cat();
	Cat(const string t);
	Cat(const Cat &other);
	Cat &operator=(const Cat &rhs);
	~Cat();

	void makeSound() const;
	Brain* getBrain(void) const;
};
