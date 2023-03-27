#include "../include/Zombie.hpp"


int main ( void )
{
	Zombie *zb1 = newZombie("Rick");

	std::cout << "\U0001F9DF ";
	zb1->announce();
	
	std::cout << "\U0001F9DF ";
	randomChump("Morty");

	delete(zb1);
	return (0);
}