#pragma once
#include "../include/Animal.hpp"

// Class declaration
class Brain {
 	public:
	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &rhs);
	virtual ~Brain();

 protected:
	std::string _ideas[100];
};
