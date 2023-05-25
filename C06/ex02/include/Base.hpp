#pragma once

// Class declaration
class Base {
	public:
		virtual ~Base();

	private:
};

Base * generate(void);
// andomly instanciates A, B or C and returns the instance as a Base pointer

void identify(Base* p);


void identify(Base& p);