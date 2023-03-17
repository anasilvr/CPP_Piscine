#include "../include/YellowPages.hpp"
#include <iostream>

Phonebook::Phonebook(void) : _index(0)
{
	return;
}

Phonebook::~Phonebook(void)
{
	std::cout << "\e[3m* THUD *\e[0m" << std::endl;
	return;
}

void		Phonebook::getIndex(void) const
{
	std::cout << "Index: " << this->_index << std::endl;
}

void	Phonebook::addContact(void)
{
	std::cout << "Adding..." << std::endl;
}

void	Phonebook::searchContact(void) const
{
	std::cout << "Searching..." << std::endl;
}