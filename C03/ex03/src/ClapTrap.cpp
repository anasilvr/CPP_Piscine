#include "../include/ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap() : _name("Default"), _hitPts(10), _energyPts(10), _attackDmg(0) { 
	std::cout << YEL << "[Default Constructor]\tClapTrap " << this->_name;
	std::cout << " created." << RESET << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string n) : _name(n), _hitPts(10), _energyPts(10), _attackDmg(0) { 
	std::cout << YEL << "[Named Constructor]\tClapTrap " << this->_name;
	std::cout << " created." << RESET << std::endl;
	return;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other) { 
	*this = other;
	std::cout << YEL << "[Copy Constructor]\tClapTrap " << this->_name;
	std::cout << " created." << RESET << std::endl;
	return;
}

// Copy assignment overload
ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
	if (this != &rhs) {
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
	if (amount < 0)
		this->_hitPts = 0;
	else
		this->_hitPts = amount;
}

void	ClapTrap::setEnergy(const int& amount){
	if (amount < 0)
		this->_energyPts = 0;
	else
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

unsigned int ClapTrap::getAttackDmg() const{
	return (this->_attackDmg);
}

void ClapTrap::attack(const std::string& target){
	if (this->_energyPts >= 1) {
		this->_energyPts -= 1;
		std::cout << BYEL << "ClapTrap " << this->_name << " attacks " << target;
		std::cout << " causing " << this->_attackDmg << " point(s) of damage!";
	}
	else
		std::cout << BWHT << "Not enough points! Attack fails.";
	std::cout << RESET << std::endl;
	return;
}

void ClapTrap::takeDamage(unsigned int amount){
	if ((int)amount < 0)
	{
		std::cout << RED << "[Damage] Invalid input. Try again" << RESET << std::endl;
		return ;
	}
	if (this->_hitPts == 0){
		std::cout << BWHT << this->_name << "'s already dead. Let him rest in peace, you monster!" << RESET << std::endl;
		return ;
	}
	if (this->_hitPts <= amount){
		this->_hitPts = 0;
		std::cout << BWHT << this->_name << " takes " << amount;
		std::cout << " point(s) of damage and dies!" << RESET << std::endl;
	}
	else if (this->_hitPts > amount){
		this->_hitPts -= amount;
		std::cout << BWHT << this->_name << " takes " << amount;
		std::cout << " point(s) of damage! Ouch! " << RESET << std::endl;
		}
	return;
}

void ClapTrap::beRepaired(unsigned int amount){
	if ((int)amount < 0)
	{
		std::cout << RED << "[Repair] Invalid input. Try again" << RESET << std::endl;
		return ;
	}
	if (this->_hitPts == 0){
		std::cout << BWHT << "Too late. :( " << this->_name;
		std::cout << " is dead and cannot repair itself." <<  RESET << std::endl;
	}
	else if (this->_energyPts >= 1){
		this->_hitPts += amount;
		std::cout << BWHT << this->_name << " repairs " << amount;
		std::cout << " hit point(s)!" << RESET << std::endl;
		this->_energyPts -= 1;
	}
	else
		std::cout << BWHT << "Not enough point(s)! Repair fails." << RESET << std::endl;
	return;
}

std::ostream& operator<<(std::ostream& out, ClapTrap const& arg){
	out << YEL << "ClapTrap "<< arg.getName();
	out << "\t[ " << "HP:" << arg.getHealth();
	out << "\t| ENERGY: " << arg.getEnergy();
	out << "| AD: " << arg.getAttackDmg() << " ]" << RESET << std::flush;
	return (out);
}
