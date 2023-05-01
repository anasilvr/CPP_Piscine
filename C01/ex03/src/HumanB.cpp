#include "../include/HumanB.hpp"
#include <iostream>

HumanB::HumanB ( std::string name ) : _name(name), _weapon(NULL) { return; }
HumanB::~HumanB ( void ) { return; }

void	HumanB::setWeapon( Weapon& weapon ) {
	this->_weapon = &weapon;
}

Weapon*	HumanB::getWeapon( void ) const { 
	return (this->_weapon);
}

void	HumanB::attack (void ) const {
	std::cout <<this->_name << " attacks with his ";
	if (this->_weapon)
		std::cout << this->_weapon->getType() << std::endl;
	else
		std::cout << "hands" << std::endl;
}