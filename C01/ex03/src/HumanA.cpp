#include "../include/HumanA.hpp"
#include <iostream>


HumanA::HumanA	( std::string name, Weapon &weapon ) : _name(name), _weapon(weapon) { return; }
HumanA::~HumanA ( void ) { return ; }

void	HumanA::setWeapon( Weapon& weapon) {
	this->_weapon = weapon;
}

Weapon& HumanA::getWeapon( void ) const {
	return (this->_weapon);
}

void	HumanA::attack( void ) const {
	std::cout << this->_name << " attacks with his ";
	std::cout << this->_weapon.getType() << std::endl;
}