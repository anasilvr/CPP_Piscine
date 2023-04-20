#include "../include/ClapTrap.hpp"
#include <iostream>

// Default constructor
ClapTrap::ClapTrap() : _name("Default"), _hitPts(10), _energyPts(10), _attackDmg(0) { 
	std::cout << "[Default Constructor]\tClapTrap " << this->_name;
	std::cout << " created." << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string n) : _name(n), _hitPts(10), _energyPts(10), _attackDmg(0) { 
	std::cout << "[Named Constructor]\tClapTrap " << this->_name;
	std::cout << " created." << std::endl;
	return;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other) { 
	*this = other;
	std::cout << "[Copy Constructor]\tClapTrap " << this->_name;
	std::cout << " created." << std::endl;
	return;
}

// Copy assignment overload
ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
	if (this != &rhs)
	{ 
		this->_name = rhs._name;
		this->_hitPts = rhs._hitPts;
		this->_energyPts = rhs._energyPts;
		this->_attackDmg = rhs._attackDmg;
	}
	return *this;
}

// Default destructor
ClapTrap::~ClapTrap() { 
	std::cout << YEL << "ClapTrap " << this->_name << " destroyed." << RESET << std::endl;
	return;
}

void	ClapTrap::setName(const std::string& n){
	this->_name = n;
}

void	ClapTrap::setHealth(const int& amount){
	this->_hitPts = amount;
}

void	ClapTrap::setEnergy(const int& amount){
	this->_energyPts = amount;
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
	if (this->_hitPts == 0){
		std::cout << "ClapTrap " << this->_name << "'s already dead." << std::endl;
		return ;
	}
	if (this->_hitPts <= amount){
		this->_hitPts = 0;
		std::cout << "ClapTrap " << this->_name << " takes " << amount;
		std::cout << " point(s) of damage and dies!" << std::endl;
	}
	else if (this->_hitPts > amount){
		this->_hitPts -= amount;
		std::cout << "ClapTrap " << this->_name << " takes " << amount;
		std::cout << " point(s) of damage! Ouch! " << std::endl;
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
