#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ClapTrap("Default_clap_name"), _name("Default")
{
	this->FragTrap::_hitPts = 100;
	this->ScavTrap::_energyPts = 50;
	this->FragTrap::_attackDmg = 30;
	std::cout << CYN << "[Default Constructor]\tClapTrap " << this->_name;
	std::cout << " created." << RESET << std::endl;
	return;
}

DiamondTrap::DiamondTrap(std::string n)
	: ClapTrap(n + "_clap_name"), _name(n){
	this->FragTrap::_hitPts = 100;
	this->ScavTrap::_energyPts = 50;
	this->FragTrap::_attackDmg = 30;
	std::cout << CYN << "[Named Constructor]\tDiamondTrap " << this->_name;
	std::cout << " created." << RESET << std::endl;
	return;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other){
	*this = other;
	std::cout << CYN << "[Copy Constructor]\tDiamondTrap " << this->_name;
	std::cout << " created." << RESET << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &rhs){
	if (this != &rhs)
	{
		ClapTrap::_name = rhs.ClapTrap::_name;
		this->_name = rhs._name;
		this->_hitPts = rhs._hitPts;
		this->_energyPts = rhs._energyPts;
		this->_attackDmg = rhs._attackDmg;
	}
	return *this;
}
	
void DiamondTrap::attack(const std::string& target){
	ScavTrap::attack(target);

}


DiamondTrap::~DiamondTrap(){
	std::cout << CYN << "DiamondTrap " << this->_name << " destroyed." << RESET << std::endl;
	return;
}

void DiamondTrap::whoAmI(){
	std::cout << CYN << "My ClapTrap name is: " << ClapTrap::_name << std::endl;
	std::cout <<"My DiamondTrap name is: " << this->_name << RESET << std::endl;

}

std::ostream& operator<<(std::ostream& out, DiamondTrap const& arg){
	out << CYN << "DiamondTrap "<< arg.getName();
	out << "\t[ " << "HP: " << arg.getHealth();
	out << " | ENERGY: " << arg.getEnergy();
	out << " | AD: " << arg.getAttackDmg() << " ]" << RESET << std::flush;
	return (out);
}