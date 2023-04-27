#include "../include/ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap() : ClapTrap("Default") { 
	std::cout << MAG <<"[Default Constructor]\tScavTrap " << this->_name;
	std::cout << " created." << RESET << std::endl;
	this->_hitPts = 100;
	this->_energyPts = 50;
	this->_attackDmg = 20;
	this->_gateKeeper = false;
	return;
}

ScavTrap::ScavTrap(std::string n) : ClapTrap(n) { 
	std::cout << MAG << "[Named Constructor]\tScavTrap " << this->_name;
	std::cout << " created." << RESET << std::endl;
	this->_hitPts = 100;
	this->_energyPts = 50;
	this->_attackDmg = 20;
	this->_gateKeeper = false;
	return;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap& other) { 
	*this = other;
	std::cout << MAG << "[Copy Constructor]\tScavTrap " << this->_name;
	std::cout << " created." << RESET << std::endl;
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
		std::cout << MAG << "ScavTrap " << this->_name << " attacks " << target;
		std::cout << " causing " << this->_attackDmg << " point(s) of damage!";
		std::cout << RESET << std::endl;
	}
	else
		std::cout << BWHT << "Not enough points! Attack fails." << RESET << std::endl;
	return;
}

void	ScavTrap::guardGate(){
	std::cout << BWHT;
	if (this->_gateKeeper == false){
		this->_gateKeeper = true;
		std::cout << BWHT << "ScavTrap " << this->_name << " enters guard mode.";
	}
	else {
		this->_gateKeeper = false;
		std::cout << BWHT << this->_name << " leaves guard mode.";
	}
	std::cout << RESET << std::endl;
}

bool	ScavTrap::guardStatus() const {
	return (this->_gateKeeper);
}

std::ostream& operator<<(std::ostream& out, ScavTrap const& arg){
	out << MAG <<"ScavTrap " << arg.getName();
	out << "\t[ " << "HP: " << arg.getHealth();
	out << " | ENERGY: " << arg.getEnergy();
	out << " | AD: " << arg.getAttackDmg(); 
	if (arg.guardStatus() == true)
		out << " | GUARD: \033[0;32mON\e[0;35m ]";
	else
		out << " | GUARD: \033[0;31mOFF\e[0;35m ]";
	out << RESET << std::flush;
	return (out);
}
