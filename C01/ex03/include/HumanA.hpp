#pragma once
#include "Weapon.hpp"

class HumanA {
	public:
	HumanA	( std::string name, Weapon& Weapon );
	~HumanA ( void );

	void	setWeapon( Weapon& weapon);
	Weapon&	getWeapon( void ) const;

	void	attack( void ) const;

	private:
	std::string _name;
	Weapon &_weapon;
};