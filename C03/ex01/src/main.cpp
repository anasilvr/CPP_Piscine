#include <iostream>
#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"

int main( void )
{
	ClapTrap A("Rick");
	ScavTrap B("Morty");
	ClapTrap C = A;
	ScavTrap D;
	D = B;

	std::cout << BWHT << "\nSTATS" << RESET << std::endl;
	std::cout << "A: " << A << std::endl;
	std::cout << "B: " << B << std::endl;
	std::cout << "C: " << C << std::endl;
	std::cout << "D: " << D << std::endl;
	std::cout << std::endl;

	std::cout << BWHT << "\n-----While loop starts-----\n" << std::endl;
	while (B.getHealth() > 20 && A.getEnergy() > 0){
		A.attack(B.getName());
		B.takeDamage(20);
		std::cout << A << std::endl;
		std::cout << B << std::endl;
		std::cout << std::endl;
	}
	std::cout << BWHT << "-----While loop ends-----\n" << std::endl;
	
	B.beRepaired(10);
	B.guardGate();
	std::cout << A << std::endl;
	std::cout << B << std::endl;
	std::cout << std::endl;

	A.attack(B.getName());
	B.takeDamage(35);
	// B dies before repairing: Repair should fail.
	B.beRepaired(5);
	A.attack(B.getName());
	std::cout << A << std::endl;
	std::cout << B << std::endl;
	std::cout << std::endl;
}