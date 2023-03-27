#include "../include/Zombie.hpp"


int main ( void )
{
	const int nb = 13;
	int count = 0;
	
	Zombie *horde = zombieHorde(nb, "Zombie");

	for (int i = 0; i < nb; i++)
	{
		std::cout << "\U0001F9DF "<< std::flush;
		horde[i].announce();
		count++;
	}
	delete [] horde;
	std::cout << "Zombies created and killed: " << count << std::endl;
	return (0);
}