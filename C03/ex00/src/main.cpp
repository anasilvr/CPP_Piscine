#include <iostream>
#include "../include/ClapTrap.hpp"

int main( void )
{
	ClapTrap A("Rick");
	ClapTrap B("Morty");
	ClapTrap C = A;
	ClapTrap D;

	std::cout << BWHT << "\nSTATS" << std::endl;
	std::cout << A << std::endl;
	std::cout << B << std::endl;
	std::cout << C << std::endl;
	std::cout << D << std::endl;
	std::cout << std::endl;

	std::cout << BWHT << "\n-----While loop starts-----\n" << std::endl;
	while (B.getHealth() > 2 && A.getEnergy() > 0){
		A.attack(B.getName());
		B.takeDamage(2);
		std::cout << A << std::endl;
		std::cout << B << std::endl;
		std::cout << std::endl;
	}
	std::cout << BWHT << "-----While loop ends-----\n" << std::endl;
	
	B.beRepaired(5);
	std::cout << A << std::endl;
	std::cout << B << std::endl;
	std::cout << std::endl;

	A.attack(B.getName());
	B.takeDamage(7);
	// B dies before repairing: Repair should fail.
	B.beRepaired(5);
	std::cout << A << std::endl;
	std::cout << B << std::endl;
	std::cout << std::endl;
}