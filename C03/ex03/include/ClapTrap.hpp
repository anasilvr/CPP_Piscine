#pragma once

#include <string>
#include <iostream>

# define BLK "\e[0;30m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define BLU "\e[0;34m"
# define MAG "\e[0;35m"
# define CYN "\e[0;36m"
# define WHT "\e[0;37m"
# define BBLK "\e[1;30m"
# define BRED "\e[1;31m"
# define BGRN "\e[1;32m"
# define BYEL "\e[1;33m"
# define BBLU "\e[1;34m"
# define BMAG "\e[1;35m"
# define BCYN "\e[1;36m"
# define BWHT "\e[1;37m"
# define RESET "\e[0m"

// Class declaration
class ClapTrap {
	public:
		ClapTrap();
		ClapTrap(std::string n);
		ClapTrap(const ClapTrap &other);

		ClapTrap &operator=(const ClapTrap &rhs);

		~ClapTrap();

		void			setName(const std::string& n);
		void			setHealth(const int& amount);
		void			setEnergy(const int& amount);
		std::string		getName() const;
		unsigned int	getHealth() const;
		unsigned int	getEnergy() const;
		unsigned int	getAttackDmg() const;

		virtual void 	attack(const std::string& target);
		void 			takeDamage(unsigned int amount);
		void 			beRepaired(unsigned int amount);

	protected:
		std::string		_name;
		unsigned int	_hitPts;
		unsigned int	_energyPts;
		unsigned int	_attackDmg;

	private:
};

std::ostream& operator<<(std::ostream& out, ClapTrap const& arg);