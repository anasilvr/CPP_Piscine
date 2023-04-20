#include <iostream>
#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"

int main( void )
{
	ScavTrap A("Bart");
	ScavTrap B("Homer");
	ScavTrap C = B;
	ScavTrap D;
	D = C;
	std::cout << BWHT << "\nSTATS\n" << RESET <<std::flush;
	std::cout << A << std::endl;
	std::cout << B << std::endl;
	std::cout << C << std::endl;
	std::cout << D << std::endl;
	std::cout << std::endl;

	C.guardGate();

	std::cout << C << std::endl;
	std::cout << "________________________________________________Start of while loop\n" << std::endl;
	while (B.getHealth() > 2 && A.getEnergy() > 0){
		A.attack(B.getName());
		B.takeDamage(2);
		std::cout << A << std::endl;
		std::cout << B << std::endl;
		std::cout << std::endl;
	}
	std::cout << "__________________________________________________End of while loop\n" << std::endl;
	
	B.guardGate();
	B.beRepaired(5);
	std::cout << A << std::endl;
	std::cout << B << std::endl;
	std::cout << std::endl;
	
	std::cout << "___________________________________________________________________\n" << std::endl;
	A.attack(B.getName());
	B.takeDamage(7); // B dies
	B.beRepaired(5); // Repair fails
	std::cout << "___________________________________________________________________\n" << std::endl;
	
	std::cout << A << std::endl;
	std::cout << B << std::endl;
	std::cout << std::endl;
}