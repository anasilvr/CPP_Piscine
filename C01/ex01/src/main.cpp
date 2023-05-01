#include "../include/Zombie.hpp"


int main ( void )
{
	int nb;
	int count = 0;

	std::cout << "How many zombies do you want to create? (Min.: 5, Máx.: = 100, Default: 13)" << std::endl;
	std::cin >> nb;
	
	if (nb < 5)
		nb = 5;
	else if (nb > 100)
		nb = 100;
	if (std::cin.eof())
		nb = 13;

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