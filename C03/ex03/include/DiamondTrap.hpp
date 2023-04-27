#pragma once

#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string _name;
public:
	DiamondTrap();
	DiamondTrap(std::string);
	DiamondTrap(const DiamondTrap&);

	DiamondTrap& operator=(const DiamondTrap &rhs);
	
	~DiamondTrap();

	void whoAmI();
	void attack(const std::string& target);
};

std::ostream& operator<<(std::ostream& out, DiamondTrap const& arg);