#pragma once

#include <ctime>
#include <cstdlib>
#include <iostream>

// Class declaration
class Base {
	public:
		virtual ~Base();

	private:
};

// randomly instanciates A, B or C and returns the instance as a Base pointer
Base	*generate(void);

// prints the actual type of the object pointed to by p ("A", "B" or "C")
void	identify(Base* p);
void	identify(Base& p);