#include "../include/Harl.hpp"

Harl::Harl( void ) { return; }
Harl::~Harl( void ) { return; }

void Harl::debug( void ) { std::cout << DEBUG_MSG << std::endl; }

void Harl::info( void ) { std::cout << INFO_MSG << std::endl; }

void Harl::warning( void ) { std::cout << WARN_MSG << std::endl; }

void Harl::error( void ) { std::cout << ERROR_MSG << std::endl; }

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

	for (int i = 0; i < 4; i++)
	{
		if (!id.compare(options[i]))
		{
			std::cout << "[ " << id << " ]\n" << std::flush;
			(this->*lvl[i])();
			break ;
		}	
	}
}