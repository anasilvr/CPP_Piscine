#include "../include/Harl.hpp"

	Harl::Harl( void ) { return; }
	Harl::~Harl( void ) { return; }
	
	void Harl::debug( void ) { return; }
	void Harl::info( void ) { return; }
	void Harl::warning( void ) { return; }
	void Harl::error( void ) { return; }

	void Harl::complain( std::string id )
	{
		std::cout << "coucou" << id << std::endl;
	}