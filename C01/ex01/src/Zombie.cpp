#include "../include/Zombie.hpp"

Zombie::Zombie( void )
{ return ; }

Zombie::~Zombie( void )
{ std::cout << this->_name << " destroyed. RIP. \U0001F480" << std::endl; }

void Zombie::announce( void )
{ std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl; }

void Zombie::setName( std::string name )
{
	this->_name = name;
}

std::string Zombie::getName( void )
{
	return (this->_name);
}