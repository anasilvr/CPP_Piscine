#include <iostream>
#include "Sample.class.hpp"

Sample1::Sample1(const float nb) : pi(nb), sq(42)
{
	std::cout << "Constructor called." << std::endl;
	this->print_att();
	return;
}

Sample1::~Sample1(void){
	std::cout << "Destructor called." << std::endl;
	return;
}

void	Sample1::print_att(void) const{ // const at the end: this functions will NEVER change values. Stop compilation.
	std::cout << "nb = " << this->pi << std::endl;
	std::cout << "sq = " << this->sq << std::endl;
}

//MEMBER FUNCTIONS THAT DO NOT CHANGE VALUES: CONST!