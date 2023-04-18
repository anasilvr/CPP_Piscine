#pragma once
#include <string>

#ifndef CLAPTRAP_HPP_
#define CLAPTRAP_HPP_

// Class declaration
class ClapTrap {
	public:
		ClapTrap();
		ClapTrap(std::string n);
		ClapTrap(const ClapTrap &other);

		ClapTrap &operator=(const ClapTrap &rhs);

		~ClapTrap();

		std::string getName() const;
		unsigned int getHealth() const;
		unsigned int getEnergy() const;

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	private:
		std::string		_name;
		unsigned int	_hitPts;
		unsigned int	_energyPts;
		unsigned int	_attackDmg;

};

std::ostream& operator<<(std::ostream& out, ClapTrap const& arg);

#endif // CLAPTRAP_HPP_
