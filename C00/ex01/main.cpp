#include "./include/YellowPages.hpp"
#include <iostream>
#include <iomanip>

int main (void)
{
	Phonebook 	book;
	std::string option;

	std::cout << "\e[3m* Flipping pages sound *\e[0m" << std::endl;
	std::cout << "\e[1mWelcome to YellowPages!\e[0m\nChoose a option by typing it down:\n" << std::endl;
	std::cout << "[ \e[32mADD\e[0m | \e[33mSEARCH\e[0m | \e[31mEXIT\e[0m ]\n" << std::endl;
	std::cout << "P.s.: Make sure to use uppercase letters.\n      Use Ctrl+D at any time to quit program." << std::endl;
	while (1)
	{
		std::cout << "\e[1mWhat do you want to do?\e[0m ";
		std::cin >> option;
		if (std::cin.eof())
			break;
		if (!option.compare("ADD"))
		 	book.addContact();
		else if (!option.compare("SEARCH"))
		{
			if (book.getIndex() != 0)
				book.searchContact();
			else
				std::cout << "\e[1m\nYour phonebook is still empty.\nAdd a contact before trying to use SEARCH.\n\e[0m " << std::endl;
		}
		else if (!option.compare("EXIT"))
			break ;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	}
	return (0);
}
