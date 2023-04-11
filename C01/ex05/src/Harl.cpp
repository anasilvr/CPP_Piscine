#include "../include/Harl.hpp"

Harl::Harl( void ) { return; }
Harl::~Harl( void ) { return; }

void Harl::debug( void )
{ std::cout << DEBUG_MSG << std::endl; }

void Harl::info( void )
{ std::cout << INFO_MSG << std::endl; }

void Harl::warning( void )
{ std::cout << WARN_MSG << std::endl; }

void Harl::error( void )
{ std::cout << ERROR_MSG << std::endl; }

void Harl::complain( std::string id )
{
	std::string options[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	funcPtr lvl = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error 
	};

	for (int i = 0; i < 5; i++)
	{
		if (i == 4)
			std::cout << "LEARN TO READ AND CHOOSE A VALID OPTION!" << std::endl;
		if (!id.compare(options[i]))
		{
			(this->*lvl[i])();
			break ;
		}	
	}
}