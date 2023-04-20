#include <iostream>
#include "../include/ClapTrap.hpp"

int main( void )
{
	ClapTrap A("Rick");
	ClapTrap B("Morty");
	ClapTrap C = A;
	ClapTrap D;

	// std::cout << A << std::endl;
	// std::cout << B << std::endl;
	// std::cout << C << std::endl;
	// std::cout << D << std::endl;
	std::cout << std::endl;

	while (B.getHealth() > 2 && A.getEnergy() > 0){
		A.attack(B.getName());
		B.takeDamage(2);
		std::cout << A << std::endl;
		std::cout << B << std::endl;
		std::cout << std::endl;
	}
	std::cout << "_______________________________________________\n" << std::endl;
	B.beRepaired(5);

	std::cout << A << std::endl;
	std::cout << B << std::endl;
	std::cout << std::endl;
	std::cout << "_______________________________________________\n" << std::endl;
	A.attack(B.getName());
	B.takeDamage(15);
	// B dies before repairing: Repair should fail.
	B.beRepaired(5);
	std::cout << "_______________________________________________\n" << std::endl;
	
	std::cout << A << std::endl;
	std::cout << B << std::endl;
	std::cout << std::endl;
}