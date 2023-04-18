#include "../include/ClapTrap.hpp"
#include <iostream>

// Default constructor
ClapTrap::ClapTrap() : _name("Default"), _hitPts(10), _energyPts(10), _attackDmg(0) { 
	std::cout << "[Default Constructor] ClapTrap " << this->_name << " created.\n[ ";
	std::cout << "HP: " << this->_hitPts << " | ENERGY: " << this->_energyPts;
	std::cout << " | DMG: " << this->_attackDmg << " ]\n" << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string n) : _name(n), _hitPts(10), _energyPts(10), _attackDmg(0) { 
	std::cout << "[Named Constructor] ClapTrap " << this->_name << " created.\n[ ";
	std::cout << "HP: " << this->_hitPts << " | ENERGY: " << this->_energyPts;
	std::cout << " | DMG: " << this->_attackDmg << " ]\n" << std::endl;
	return;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), 
	_hitPts(other._hitPts), _energyPts(other._energyPts), _attackDmg(other._attackDmg) { 
	std::cout << "[Copy Constructor] ClapTrap " << this->_name << " created.\n[ ";
	std::cout << "HP: " << this->_hitPts << " | ENERGY: " << this->_energyPts;
	std::cout << " | DMG: " << this->_attackDmg << " ]\n" << std::endl;
	return;
}

// Copy assignment overload
ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
	this->_name = rhs._name;
	this->_hitPts = rhs._hitPts;
	this->_energyPts = rhs._energyPts;
	this->_attackDmg = rhs._attackDmg;
	return *this;
}

// Default destructor
ClapTrap::~ClapTrap() { 
	std::cout << "ClapTrap " << this->_name << " destroyed." << std::endl;
	return;
}

std::string ClapTrap::getName() const{
	return (this->_name);
}

unsigned int ClapTrap::getHealth() const{
	return (this->_hitPts);
}

unsigned int ClapTrap::getEnergy() const{
	return (this->_energyPts);
}

void ClapTrap::attack(const std::string& target){
	if (this->_energyPts >= 1) {
		std::cout << "ClapTrap " << this->_name << " attacks " << target;
		std::cout << " causing " << this->_attackDmg << " point(s) of damage!";
		std::cout << std::endl;
		this->_energyPts -= 1;
	}
	else
		std::cout << "Not enough points! Attack fails." << std::endl;
	return;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (this->_hitPts >= amount){
		this->_hitPts -= amount;
		std::cout << "ClapTrap " << this->_name << " takes " << amount;
		std::cout << " point(s) of damage! Ouch! " << std::endl;
		}
	if (this->_hitPts == 0){
		std::cout << "ClapTrap " << this->_name << "'s KO." << std::endl;
	}
	return;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->_hitPts == 0){
		std::cout << "Too late. :( ClapTrap " << this->_name;
		std::cout << " is dead and cannot repair itself." << std::endl;
	}
	else if (this->_energyPts >= 1){
		if (this->_hitPts + amount > 10)
			this->_hitPts = 10;
		else
			this->_hitPts += amount;
		std::cout << "ClapTrap " << this->_name << " repairs " << amount;
		std::cout << " hit point(s)!" << std::flush;
		std::cout << std::endl;
		this->_energyPts -= 1;
	}
	else
		std::cout << "Not enough point(s)! Repair fails." << std::endl;
	return;
}

std::ostream& operator<<(std::ostream& out, ClapTrap const& arg){
	out << arg.getName() << "\t[ " << "HP: " << arg.getHealth() << " | ENERGY: " << arg.getEnergy() << " ]";
	return (out);
}
