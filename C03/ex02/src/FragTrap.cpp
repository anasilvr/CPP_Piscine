#include "../include/FragTrap.hpp"
#include <iostream>

// Default constructor
FragTrap::FragTrap() : ClapTrap("Default") { 
	std::cout << GRN << "[Default Constructor]\tFragTrap " << this->_name;
	std::cout << " created." << RESET << std::endl;
	return;
}

FragTrap::FragTrap(std::string n) : ClapTrap(n) { 
	std::cout << GRN << "[Named Constructor]\tFragTrap " << this->_name;
	std::cout << " created." << RESET << std::endl;
	this->_hitPts = 100;
	this->_energyPts = 100;
	this->_attackDmg = 30;
	return;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap& other) { 
	*this = other;
	std::cout << GRN << "[Copy Constructor]\tFragTrap " << this->_name;
	std::cout << " created." << RESET << std::endl;
	this->_hitPts = 100;
	this->_energyPts = 100;
	this->_attackDmg = 30;
	return;
}

// Copy assignment overload
FragTrap &FragTrap::operator=(const FragTrap &rhs) {
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_hitPts = rhs._hitPts;
		this->_energyPts = rhs._energyPts;
		this->_attackDmg = rhs._attackDmg;
	}
	return *this;
}

// Default destructor
FragTrap::~FragTrap() { 
	std::cout << GRN << "FragTrap " << this->_name << " destroyed." << RESET << std::endl;
	return;
}

void FragTrap::highFivesGuys(void) {
	if (this->_hitPts > 0)
		std::cout << GRN << "FragTrap " << this->_name << " would like to high five everyone! 🖐" << RESET << std::endl;
	else
		std::cout << GRN << "FragTrap " << this->_name << " would like to high five everyone (from heaven)! 🖐" << RESET << std::endl;
	return;
}

std::ostream& operator<<(std::ostream& out, FragTrap const& arg){
	out << GRN << "FragTrap "<< arg.getName();
	out << "\t[ " << "HP: " << arg.getHealth();
	out << " | ENERGY: " << arg.getEnergy();
	out << " | AD: " << arg.getAttackDmg() << " ]" << RESET << std::flush;
	return (out);
}
