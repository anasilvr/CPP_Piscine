#include <iostream>
#include "../include/ClapTrap.hpp"
#include "../include/FragTrap.hpp"
#include "../include/ScavTrap.hpp"

int main( void )
{
	ClapTrap A("Homer");
	ScavTrap B("Marge");
	FragTrap C("Bart");
	ClapTrap D = A;
	ScavTrap E = B;
	FragTrap F = C;

	std::cout << BWHT << "\nSTATS" << RESET << std::endl;
	std::cout << "A: " << A << std::endl;
	std::cout << "B: " << B << std::endl;
	std::cout << "C: " << C << std::endl;
	std::cout << "D: " << D << std::endl;
	std::cout << "E: " << E << std::endl;
	std::cout << "F: " << F << std::endl;
	std::cout << std::endl;

	std::cout << BWHT << "\n-----While loop starts-----\n" << std::endl;
	while (C.getHealth() > 20 && B.getEnergy() > 0){
		B.attack(C.getName());
		C.takeDamage(20);
		std::cout << A << std::endl;
		std::cout << B << std::endl;
		std::cout << std::endl;
	}
	std::cout << BWHT << "-----While loop ends-----\n" << std::endl;

	C.beRepaired(-1);	
	C.beRepaired(10);
	B.guardGate();
	std::cout << BWHT << "\nSTATS" << RESET << std::endl;
	std::cout << A << std::endl;
	std::cout << B << std::endl;
	std::cout << C << std::endl;
	std::cout << std::endl;

	B.attack(A.getName());
	C.takeDamage(B.getAttackDmg());
	C.takeDamage(B.getAttackDmg());
	// B dies before repairing: Repair should fail.
	C.beRepaired(5);
	B.attack(A.getName());
	C.takeDamage(5);

	C.highFivesGuys();
	
	std::cout << BWHT << "\nSTATS" << RESET << std::endl;
	std::cout << A << std::endl;
	std::cout << B << std::endl;
	std::cout << C << std::endl;
	std::cout << std::endl;
}