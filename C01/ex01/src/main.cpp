#include "../include/Zombie.hpp"


int main ( void )
{
	int nb = 10;
	int count = 0;

	Zombie *horde = zombieHorde(nb, "Zombie");

	for (int i = 0; i < nb; i++)
	{
		std::cout << "\U0001F9DF [" << i + 1 << "] " << std::flush;
		horde[i].announce();
		count++;
	}
	delete [] horde;
	std::cout << "Zombies created and killed: " << count << std::endl;
	return (0);
}