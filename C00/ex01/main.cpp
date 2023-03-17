#include "./include/YellowPages.hpp"
#include <iostream>
#include <iomanip>

int main (void)
{
	Phonebook book;
	std::string option;

	std::cout << "\e[3m* Flipping pages sound *\e[0m" << std::endl;
	std::cout << "\e[1mWelcome to YellowPages!\e[0m\nChoose a option by typing it down:\n" << std::endl;
	std::cout << "[ \e[32mADD\e[0m | \e[33mSEARCH\e[0m | \e[31mEXIT\e[0m ]\n" << std::endl;
	std::cout << "P.s.: Make sure to use uppercase letters.\n" << std::endl;
	while (1)
	{
		std::cout << "What do you want to do? ";
		std::cin >> option;
		if (std::cin.eof())
			return (-1);
		if (!option.compare("ADD"))
		 	book.addContact();
		else if (!option.compare("SEARCH"))
			book.searchContact();
		else if (!option.compare("EXIT"))
			break ;
	}
	return (0);
	// watch videos on intra
	// create classes
	// parse and check input ,code add, search, exit functions
}