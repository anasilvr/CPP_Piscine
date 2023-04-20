#include "../include/ScavTrap.hpp"
#include <iostream>

// Default constructor
ScavTrap::ScavTrap() : ClapTrap("Default") { 
	std::cout << "[Default Constructor]\tScavTrap " << this->_name;
	std::cout << " created." << std::endl;
	this->_hitPts = 100;
	this->_energyPts = 50;
	this->_attackDmg = 20;
	this->_gateKeeper = false;
	return;
}

ScavTrap::ScavTrap(std::string n) : ClapTrap(n) { 
	std::cout << "[Named Constructor]\tScavTrap " << this->_name;
	std::cout << " created." << std::endl;
	this->_hitPts = 100;
	this->_energyPts = 50;
	this->_attackDmg = 20;
	this->_gateKeeper = false;
	return;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap& other) { 
	*this = other;
	std::cout << "[Copy Constructor]\tScavTrap " << this->_name;
	std::cout << " created." << std::endl;
	this->_gateKeeper = false;
	return;
}

// Copy assignment overload
ScavTrap &ScavTrap::operator=(const ScavTrap &rhs) {
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_hitPts = rhs._hitPts;
		this->_energyPts = rhs._energyPts;
		this->_attackDmg = rhs._attackDmg;
	}
	return *this;
}

// Default destructor
ScavTrap::~ScavTrap() { 
	std::cout << MAG << "ScavTrap " << this->_name << " destroyed." << RESET <<std::endl;
	return;
}

void ScavTrap::attack(const std::string& target){
	if (this->_energyPts >= 1) {
		this->_energyPts -= 1;
		std::cout << "ScavTrap " << this->_name << " attacks " << target;
		std::cout << " causing " << this->_attackDmg << " point(s) of damage!";
		std::cout << std::endl;
	}
	else
		std::cout << "Not enough points! Attack fails." << std::endl;
	return;
}

void	ScavTrap::guardGate(){
	std::cout << BWHT;
	if (this->_gateKeeper == false){
		this->_gateKeeper = true;
		std::cout << this->_name << " enters guard mode." << std::endl;
	}
	else {
		this->_gateKeeper = false;
		std::cout << this->_name << " leaves guard mode." << std::endl;
	}
	std::cout << RESET << std::flush;
}

bool	ScavTrap::guardStatus() const {
	return (this->_gateKeeper);
}

std::ostream& operator<<(std::ostream& out, ScavTrap const& arg){
	out << MAG <<"ScavTrap " << arg.getName() << "\t[ " << "HP: " << arg.getHealth() << " | ENERGY: " << arg.getEnergy() << std::flush;
	if (arg.guardStatus() == true)
		out << " | GUARD: \033[0;32mON\033[0;37m ]" << std::flush;
	else
		out << " | GUARD: \033[0;31mOFF\033[0;37m ]" << std::flush;
	std::cout << RESET;
	return (out);
}
